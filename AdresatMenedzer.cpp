#include "AdresatMenedzer.h"


void AdresatMenedzer::dodawanieAdresata()
{
    Adresat adresat;
    system("cls");

    adresat.UstawIdUzytkownika(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    adresat.UstawIdAdresata(pobierzIdNowegoAdresata()+1);
    cout << " >>> PODAJ DANE ADREATA <<<" << endl;
    cout << "---------------------------" << endl;

    cout << "Podaj imie: ";
    adresat.UstawImie(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj nazwisko: ";
    adresat.UstawNazwisko(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj numer telefonu: ";
    adresat.UstawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj email: ";
    adresat.UstawEmail(MetodyPomocnicze::wczytajLinie());
    cout << "Podaj adres: ";
    adresat.UstawAdres(MetodyPomocnicze::wczytajLinie());
    adresaci.push_back(adresat);
    plikZAdresatami.dopiszAdresataDoPliku(adresat);
    cout << endl << "Adresat dodany pomyslnie" << endl << endl;
    system("pause");
}

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    return plikZAdresatami.pobierzIdOstatniegoAdresata();
}

void AdresatMenedzer::wypiszWszystkichAdresatowUzytkownika()
{
    system("cls");
    cout << " >>> WSZYSCY ADRESACI  <<<" << endl;
    cout << "---------------------------" << endl;
    for (int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            cout << adresaci[i].pobierzIdAdresata() <<". "<< adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko()<<endl;
            cout << "tel: " << adresaci[i].pobierzNumerTelefonu()<<endl;
            cout << "email: " << adresaci[i].pobierzEmail()<<endl;
            cout << "adres: " << adresaci[i].pobierzAdres()<<endl;
            cout << "---------------------------"<<endl;

        }
    }
}

int AdresatMenedzer::usunAdresata(){
    int idUsuwanegoAdresata = 0;
    int numerLiniiUsuwanegoAdresata = 0;

    system("cls");
    cout << ">>> USUWANIE WYBRANEGO ADRESATA <<<" << endl << endl;
    idUsuwanegoAdresata = podajIdWybranegoAdresata();

    char znak;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzIdAdresata() == idUsuwanegoAdresata)
        {
            czyIstniejeAdresat = true;
            cout << endl << "Potwierdz naciskajac klawisz 't': ";
            znak = MetodyPomocnicze::wczytajZnak();
            if (znak == 't')
            {
                plikZAdresatami.usunWybranegoAdresata(idUsuwanegoAdresata);
                adresaci.erase(itr);
                cout << endl << endl << "Szukany adresat zostal USUNIETY" << endl << endl;
                system("pause");
                return idUsuwanegoAdresata;
            }
            else
            {
                cout << endl << endl << "Wybrany adresat NIE zostal usuniety" << endl << endl;
                system("pause");
                return 0;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata w ksiazce adresowej" << endl << endl;
        system("pause");
    }
    return 0;
};



int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}
