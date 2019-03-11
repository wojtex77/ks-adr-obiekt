#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika()
{
    uzytkownikMenedzer.rejestracjaUzytkownika();

};

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow()
{
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

};

void KsiazkaAdresowa::wyswietlMenuLogowania()
{
    system("cls");
    cout << "    >>> MENU  GLOWNE <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Rejestracja" << endl;
    cout << "2. Logowanie" << endl;
    cout << "9. Koniec programu" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";
};

int KsiazkaAdresowa::logowanieUzytkownika()
{
    return uzytkownikMenedzer.logowanieUzytkownika();
};

int KsiazkaAdresowa::menuLogowania()
{
    char wybor='0';
    do
    {
        wyswietlMenuLogowania();
        cin >>wybor;
        switch (wybor)
        {
        case ('2'):
        {
            cout <<endl<< "LOGOWANIE"<<endl;
            return logowanieUzytkownika(); //zwraca ID zalogowanego uzytkownika
            break;
        }
        case ('1'):
        {
            cout <<endl<< "REJESTRACJA"<<endl;
            rejestracjaUzytkownika();
            break;
        }


        case ('9'):
        {
            exit(0);

        }
        default:
            cout <<endl<< "Niepoprawny wybor";
            Sleep(1500);
            break;
        }

    }
    while (wybor!=9);
};

    void KsiazkaAdresowa::wyswietlMenuUzytkownika(){
    system("cls");
    cout << " >>> MENU UZYTKOWNIKA <<<" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Dodaj adresata" << endl;
    cout << "2. Wyszukaj po imieniu" << endl;
    cout << "3. Wyszukaj po nazwisku" << endl;
    cout << "4. Wyswietl adresatow" << endl;
    cout << "5. Usun adresata" << endl;
    cout << "6. Edytuj adresata" << endl;
    cout << "---------------------------" << endl;
    cout << "7. Zmien haslo" << endl;
    cout << "8. Wyloguj sie" << endl;
    cout << "---------------------------" << endl;
    cout << "Twoj wybor: ";

    };


int KsiazkaAdresowa::menuUzytkownika(int IdZalogowanegoUzytkownika)
{
    char wybor='0';
    do
    {
        wyswietlMenuUzytkownika();
        cin >>wybor;
        switch (wybor)
        {
        case ('1'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('2'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('3'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('4'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('5'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('6'):
        {
            cout << "W trakcie opracowywania";
            Sleep(1000);
            break;
        }
        case ('7'):
        {
            uzytkownikMenedzer.zmianaHaslaZalogowanegoUzytkownika();
            Sleep(1000);
            break;
        }

        case ('8'):
        {
            menuLogowania();
            break;
        }
        default:
            cout <<endl<< "Niepoprawny wybor";
            Sleep(1500);
            break;
        }

    }
    while (wybor!=8);
};
