#include "KsiazkaAdresowa.h"

void KsiazkaAdresowa::rejestracjaUzytkownika(){
    Uzytkownik uzytkownik = podajDaneNowegoUzytkownika ();

    uzytkownicy.push_back(uzytkownik);
    //dopiszUzytkownikaDoPliku(uzytkownik);
    cout << endl << "Konto zalozono pomyslnie" << endl << endl;
    system("pause");
};

Uzytkownik KsiazkaAdresowa::podajDaneNowegoUzytkownika(){
    Uzytkownik uzytkownik;

    uzytkownik.ustawId(pobierzIdNowegoUzytkownika());

    string login;
    do {
        cout << "Podaj login:";
        cin >> login;
        uzytkownik.ustawLogin(login);
    } while (czyIstniejeLogin(uzytkownik.pobierzLogin()) == true);
    cout << "Podaj haslo:" ;
    string haslo;
    cin >> haslo;
    uzytkownik.ustawHaslo(haslo);

    return uzytkownik;
};

int KsiazkaAdresowa::pobierzIdNowegoUzytkownika(){
if (uzytkownicy.empty()==true)
    return 1;
else
    return uzytkownicy.back().pobierzId()+1;
};

bool KsiazkaAdresowa::czyIstniejeLogin(string login)
{
    vector <Uzytkownik>::iterator itr = uzytkownicy.begin();

    for (int i=0; i<uzytkownicy.size(); i++){
        if (uzytkownicy[i].pobierzLogin() == login){
            cout << endl << "Istnieje uzytkownik o takim loginie." << endl;
            return true;
        }
    }
    return false;
};

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){

    for (int i=0; i<uzytkownicy.size(); i++){
        cout << uzytkownicy[i].pobierzId() << " | ";
        cout << uzytkownicy[i].pobierzLogin() << " | ";
        cout << uzytkownicy[i].pobierzHaslo() << endl;
        }
};