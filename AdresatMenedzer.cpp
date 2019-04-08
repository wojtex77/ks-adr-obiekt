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
};

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    return plikZAdresatami.pobierzIdOstatniegoAdresata();
};

void AdresatMenedzer::wypiszWszystkichAdresatowUzytkownika()
{
    system("cls");
    cout << " >>> WSZYSCY ADRESACI  <<<" << endl;
    cout << "---------------------------" << endl;
    for (int i=0; i<adresaci.size(); i++)
    {
        if (adresaci[i].pobierzIdUzytkownika()==ID_ZALOGOWANEGO_UZYTKOWNIKA)
        {
            cout << adresaci[i].pobierzImie() << " " << adresaci[i].pobierzNazwisko()<<endl;
            cout << "tel: " << adresaci[i].pobierzNumerTelefonu()<<endl;
            cout << "email: " << adresaci[i].pobierzEmail()<<endl;
            cout << "adres: " << adresaci[i].pobierzAdres()<<endl;
            cout << "---------------------------"<<endl;

        }
    }
};
