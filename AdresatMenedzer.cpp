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
}



int AdresatMenedzer::podajIdWybranegoAdresata()
{
    int idWybranegoAdresata = 0;
    cout << "Podaj numer ID Adresata: ";
    idWybranegoAdresata  = MetodyPomocnicze::wczytajLiczbeCalkowita();
    return idWybranegoAdresata;
}

int AdresatMenedzer::edytujAdresata (){
    system("cls");
    Adresat adresat;
    int idEdytowanegoAdresata = 0;
    int numerLiniiEdytowanegoAdresata = 0;
    string liniaZDanymiAdresata = "";

    cout << ">>> EDYCJA WYBRANEGO ADRESATA <<<" << endl << endl;
    idEdytowanegoAdresata = podajIdWybranegoAdresata();

    char wybor;
    bool czyIstniejeAdresat = false;

    for (vector <Adresat>::iterator itr = adresaci.begin(); itr != adresaci.end(); itr++)
    {
        if (itr -> pobierzIdAdresata() == idEdytowanegoAdresata)
        {
            czyIstniejeAdresat = true;
            wybor = wybierzOpcjeZMenuEdycja();

            switch (wybor)
            {
            case '1':
                cout << "Podaj nowe imie: ";
                itr -> UstawImie(MetodyPomocnicze::wczytajLinie());
                itr -> UstawImie(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzImie()));
                plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '2':
                cout << "Podaj nowe nazwisko: ";
                itr -> UstawNazwisko(MetodyPomocnicze::wczytajLinie());
                itr -> UstawNazwisko(MetodyPomocnicze::zamienPierwszaLitereNaDuzaAPozostaleNaMale(itr -> pobierzNazwisko()));
                plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '3':
                cout << "Podaj nowy numer telefonu: ";
                itr -> UstawNumerTelefonu(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '4':
                cout << "Podaj nowy email: ";
                itr -> UstawEmail(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '5':
                cout << "Podaj nowy adres zamieszkania: ";
                itr -> UstawAdres(MetodyPomocnicze::wczytajLinie());
                plikZAdresatami.zaktualizujDaneEdytowanegoAdresata(*itr, idEdytowanegoAdresata);
                break;
            case '6':
                cout << endl << "Powrot do menu uzytkownika" << endl << endl;
                break;
            default:
                cout << endl << "Nie ma takiej opcji w menu! Powrot do menu uzytkownika." << endl << endl;
                break;
            }
        }
    }
    if (czyIstniejeAdresat == false)
    {
        cout << endl << "Nie ma takiego adresata." << endl << endl;
    }
    system("pause");
}

char AdresatMenedzer::wybierzOpcjeZMenuEdycja()
{
    char wybor;

    cout << endl << "   >>> MENU  EDYCJA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "Ktore dane zaktualizowac: " << endl;
    cout << "1 - Imie" << endl;
    cout << "2 - Nazwisko" << endl;
    cout << "3 - Numer telefonu" << endl;
    cout << "4 - Email" << endl;
    cout << "5 - Adres" << endl;
    cout << "6 - Powrot " << endl;
    cout << endl << "Twoj wybor: ";
    wybor = MetodyPomocnicze::wczytajZnak();

    return wybor;
}
