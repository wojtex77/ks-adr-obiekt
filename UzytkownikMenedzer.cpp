#include "UzytkownikMenedzer.h"



void UzytkownikMenedzer::rejestracjaUzytkownika()
{
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika ();

    uzytkownicy.push_back(uzytkownik);
    plikZUzytkownikami.dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
}

Uzytkownik UzytkownikMenedzer::podajDaneNowegoUzytkownika()
{
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do
    {
        cout << "Podaj login:";
        cin >> login;
        uzytkownik.ustawLogin(login);
    }
    while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    cout << "Podaj haslo:" ;
    string haslo;
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
}
int UzytkownikMenedzer::pobierzIdNowegoUzytkownika()
{
    if (uzytkownicy.empty()==true)
        return 1;
    else
        return uzytkownicy.back().pobierzId()+1;
}

bool UzytkownikMenedzer::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        if (uzytkownicy[i].pobierzLogin() == login)
        {
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
}

void UzytkownikMenedzer::wypiszWszystkichUzytkownikow()
{

    for (int i=0; i<uzytkownicy.size(); i++)
    {
        cout << uzytkownicy[i].pobierzId() << " | ";
        cout << uzytkownicy[i].pobierzLogin() << " | ";
        cout << uzytkownicy[i].pobierzHaslo() << endl;
    }
}

void UzytkownikMenedzer::logowanieUzytkownika()
{
    Uzytkownik uzytkownik;
    string login = "", haslo = "";
    bool czyPoprawneHaslo=false;
    bool czyIstniejeLogin=false;
    bool czyWykorzystanoLimit=false;
    idZalogowanegoUzytkownika=0;

    cout << "Podaj login: ";
    cin >> login;

    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();
    while ((itr != uzytkownicy.end())&&(czyPoprawneHaslo==false)&&(czyWykorzystanoLimit==false))
    {
        if (itr -> pobierzLogin()== login)
        {
            czyIstniejeLogin=true;
            for (int iloscProb=3; iloscProb>0; iloscProb--)
            {
                cout << "Podaj haslo (pozostalo prob: "<< iloscProb <<"): ";
                cin >> haslo;
                if (itr -> pobierzHaslo() == haslo)
                {
                    czyPoprawneHaslo=true;
                    cout << endl << "Zalogowales sie." << endl << endl;
                    system("pause");
                    idZalogowanegoUzytkownika=itr -> pobierzId();
                    iloscProb=0;
                }
                if ((iloscProb==1)&&(czyPoprawneHaslo==false))
                    czyWykorzystanoLimit=true;
            }
        }
        else
            itr++;
    }
    if (czyIstniejeLogin==false)
    {
        cout << "Nie ma uzytkownika z takim loginem!" << endl << endl;
        system("pause");
    }
    if (czyWykorzystanoLimit==true)
    {
        cout << "Wyczerpano limit prob!" << endl << endl;
        system("pause");
    }
}

/*{
    if (itr -> pobierzLogin()== login)
    {
                for (int iloscProb = 3; iloscProb > 0; iloscProb--)
                {
                    cout << "Podaj haslo. Pozostalo prob: " << iloscProb << ": ";
                    cin >> haslo;

                    if (itr -> pobierzHaslo() == haslo)
                    {
                        cout << endl << "Zalogowales sie." << endl << endl;
                        system("pause");
                        idZalogowanegoUzytkownika=itr -> pobierzId();
                        //return itr -> pobierzId();
                    }
                }
                cout << "Wprowadzono 3 razy bledne haslo." << endl;
                system("pause");
                //return 0;
            }
            itr++;
        }
        cout << "Nie ma uzytkownika z takim loginem" << endl << endl;
        system("pause");
        //return 0;*/





void UzytkownikMenedzer::zmianaHaslaZalogowanegoUzytkownika()
{
    string noweHaslo = "";
    cout << "Podaj nowe haslo: ";
    cin >> noweHaslo;

    for (vector <Uzytkownik>::iterator itr = uzytkownicy.begin(); itr != uzytkownicy.end(); itr++)
    {
        if (itr -> pobierzId() == idZalogowanegoUzytkownika)
        {
            itr -> ustawHaslo(noweHaslo);
            cout << "Haslo zostalo zmienione." << endl << endl;
            system("pause");
        }
    }
    plikZUzytkownikami.zapiszWszystkichUzytkownikowDoPliku(uzytkownicy);

}

int UzytkownikMenedzer::pobierzIdZalogowanegoUzytkownika (){
    return idZalogowanegoUzytkownika;
}

void UzytkownikMenedzer::wylogujUzytkownika(){
    idZalogowanegoUzytkownika=0;
}
