#include "PlikZAdresatami.h"

vector <Adresat> PlikZAdresatami::wczytajAdresatowZPliku(int idZalogowanegoUzytkownika)
{
    Adresat adresat;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    vector <Adresat> wczytaniAdresaci;

    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true)
    {
        while (getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            adresat = pobierzDaneAdresata(daneJednegoAdresataOddzielonePionowymiKreskami);
            if (adresat.pobierzIdUzytkownika()==idZalogowanegoUzytkownika){
                wczytaniAdresaci.push_back(adresat);
            }
            idOstatniegoAdresata=adresat.pobierzIdAdresata();
        }
        plikTekstowy.close();
    }
    return wczytaniAdresaci;
}

Adresat PlikZAdresatami::pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    Adresat adresat;
    string pojedynczaDanaAdresata = "";
    int numerPojedynczejDanejAdresata = 1;

    for (unsigned int pozycjaZnaku = 0; pozycjaZnaku < daneJednegoAdresataOddzielonePionowymiKreskami.length(); pozycjaZnaku++)
    {
        if (daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku] != '|')
        {
            pojedynczaDanaAdresata += daneJednegoAdresataOddzielonePionowymiKreskami[pozycjaZnaku];
        }
        else
        {
            switch(numerPojedynczejDanejAdresata)
            {
            case 1:
                adresat.UstawIdAdresata(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 2:
                adresat.UstawIdUzytkownika(atoi(pojedynczaDanaAdresata.c_str()));
                break;
            case 3:
                adresat.UstawImie(pojedynczaDanaAdresata);
                break;
            case 4:
                adresat.UstawNazwisko(pojedynczaDanaAdresata);
                break;
            case 5:
                adresat.UstawNumerTelefonu(pojedynczaDanaAdresata);
                break;
            case 6:
                adresat.UstawEmail(pojedynczaDanaAdresata);
                break;
            case 7:
                adresat.UstawAdres(pojedynczaDanaAdresata);
                break;
            }
            pojedynczaDanaAdresata = "";
            numerPojedynczejDanejAdresata++;
        }
    }
    return adresat;
}



bool PlikZAdresatami::czyPlikJestPusty(fstream *plikTekstowy)
{
    plikTekstowy->seekg(0, ios::end);
    if (plikTekstowy->tellg() == 0)
        return true;
    else
        return false;
}


void PlikZAdresatami::dopiszAdresataDoPliku(Adresat adresat)
{
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::app);

    if (plikTekstowy.good() == true)
    {
        liniaZDanymiAdresata = zamienDaneAdresatowNaLinieZDanymiOddzielonaPionowymiKreskami(adresat);

        if (czyPlikJestPusty(&plikTekstowy) == true)
        {
            plikTekstowy << liniaZDanymiAdresata;
            idOstatniegoAdresata=adresat.pobierzIdAdresata();
        }
        else
        {
            plikTekstowy << endl << liniaZDanymiAdresata;
            idOstatniegoAdresata++;
        }
        plikTekstowy.close();
    }
    else
        cout << "Nie udalo sie otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI<< " i zapisac w nim danych." << endl;
}


string PlikZAdresatami::zamienDaneAdresatowNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat)
{
    string liniaZDanymiAdresata= "";


    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdAdresata())+ '|';
    liniaZDanymiAdresata += MetodyPomocnicze::konwerjsaIntNaString(adresat.pobierzIdUzytkownika())+ '|';
    liniaZDanymiAdresata += adresat.pobierzImie() + '|';
    liniaZDanymiAdresata += adresat.pobierzNazwisko() + '|';
    liniaZDanymiAdresata += adresat.pobierzNumerTelefonu() + '|';
    liniaZDanymiAdresata += adresat.pobierzEmail() + '|';
    liniaZDanymiAdresata += adresat.pobierzAdres() + '|';

    return liniaZDanymiAdresata;
}


void PlikZAdresatami::zapiszWszystkichAdresatowDoPliku(vector <Adresat> adresaci)
{
    fstream plikTekstowy;
    string liniaZDanymiAdresata = "";
    vector <Adresat>::iterator itrKoniec = --adresaci.end();

    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::out);

    if (plikTekstowy.good() == true)
    {
        for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
        {
            liniaZDanymiAdresata= zamienDaneAdresatowNaLinieZDanymiOddzielonaPionowymiKreskami(*itr);

            if (itr == itrKoniec)
            {
                plikTekstowy << liniaZDanymiAdresata;
            }
            else
            {
                plikTekstowy << liniaZDanymiAdresata << endl;
            }
            liniaZDanymiAdresata = "";
        }
        plikTekstowy.close();
    }
    else
    {
        cout << "Nie mozna otworzyc pliku " << NAZWA_PLIKU_Z_ADRESATAMI << endl;
    }
}


int PlikZAdresatami::pobierzIdOstatniegoAdresata(){
    return idOstatniegoAdresata;
}


void PlikZAdresatami::usunWybranegoAdresata(int idUsuwanegoAdresata)
{

    int numerUsuwanejLinii=0;


    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream odczytywanyPlikTekstowy, tymczasowyPlikTekstowy;
    odczytywanyPlikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);
    tymczasowyPlikTekstowy.open(nazwaTymczasowegoPlikuZAdresatami.c_str(), ios::out);


    if (odczytywanyPlikTekstowy.good() == true && idUsuwanegoAdresata != 0)
    {
        while(getline(odczytywanyPlikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idUsuwanegoAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                numerUsuwanejLinii=numerLiniiWPlikuTekstowym;
            }

                // Tych przypadkow jest tyle, gdyz chcemy osiagnac taki efekt,
                // aby na koncu pliku nie bylo pustej linii
                if (numerLiniiWPlikuTekstowym == numerUsuwanejLinii) {}
                else if (numerLiniiWPlikuTekstowym == 1 && numerLiniiWPlikuTekstowym != numerUsuwanejLinii)
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerLiniiWPlikuTekstowym == 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerLiniiWPlikuTekstowym > 2 && numerUsuwanejLinii == 1)
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;
                else if (numerLiniiWPlikuTekstowym > 1 && numerUsuwanejLinii != 1)
                    tymczasowyPlikTekstowy << endl << daneJednegoAdresataOddzielonePionowymiKreskami;

                numerLiniiWPlikuTekstowym++;


        }
        if (czyIstniejeAdresat == false)
        {
            odczytywanyPlikTekstowy.close();
            numerUsuwanejLinii=0;
        }
    }
    odczytywanyPlikTekstowy.close();
    tymczasowyPlikTekstowy.close();

    usunOdczytywanyPlik(NAZWA_PLIKU_Z_ADRESATAMI);
    zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(nazwaTymczasowegoPlikuZAdresatami, NAZWA_PLIKU_Z_ADRESATAMI);
}

int PlikZAdresatami::pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami)
{
    int pozycjaRozpoczeciaIdAdresata = 0;
    int idAdresata = MetodyPomocnicze::konwersjaStringNaInt(pobierzLiczbe(daneJednegoAdresataOddzielonePionowymiKreskami, pozycjaRozpoczeciaIdAdresata));
    return idAdresata;
}

void PlikZAdresatami::usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem)
{
    if (remove(nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nie udalo sie usunac pliku " << nazwaPlikuZRozszerzeniem << endl;
}

void PlikZAdresatami::zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem)
{
    if (rename(nazwaTymczasowegoPlikuZRozszerzeniem.c_str(), nazwaPlikuZRozszerzeniem.c_str()) == 0) {}
    else
        cout << "Nazwa pliku nie zostala zmieniona." << nazwaPlikuZRozszerzeniem << endl;
}

string PlikZAdresatami::pobierzLiczbe(string tekst, int pozycjaZnaku)
{
    string liczba = "";
    while(isdigit(tekst[pozycjaZnaku]) == true)
    {
        liczba += tekst[pozycjaZnaku];
        pozycjaZnaku ++;
    }
    return liczba;
}

int PlikZAdresatami::zwrocNumerLiniiSzukanegoAdresata(int idAdresata)
{
    bool czyIstniejeAdresat = false;
    int numerLiniiWPlikuTekstowym = 1;
    string daneJednegoAdresataOddzielonePionowymiKreskami = "";
    fstream plikTekstowy;
    plikTekstowy.open(NAZWA_PLIKU_Z_ADRESATAMI.c_str(), ios::in);

    if (plikTekstowy.good() == true && idAdresata != 0)
    {
        while(getline(plikTekstowy, daneJednegoAdresataOddzielonePionowymiKreskami))
        {
            if(idAdresata == pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(daneJednegoAdresataOddzielonePionowymiKreskami))
            {
                czyIstniejeAdresat = true;
                plikTekstowy.close();
                return numerLiniiWPlikuTekstowym;
            }
            else
                numerLiniiWPlikuTekstowym++;
        }
        if (czyIstniejeAdresat == false)
        {
            plikTekstowy.close();
            return 0;
        }
    }
    return 0;
}
