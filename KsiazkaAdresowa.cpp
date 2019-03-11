#include "KsiazkaAdresowa.h"


void KsiazkaAdresowa::rejestracjaUzytkownika(){
    uzytkownikMenedzer.rejestracjaUzytkownika();

};

void KsiazkaAdresowa::wypiszWszystkichUzytkownikow(){
    uzytkownikMenedzer.wypiszWszystkichUzytkownikow();

};

void KsiazkaAdresowa::wyswietlMenuLogowania(){
    system("cls");
    cout << "Wybierz opcje"<<endl<<endl;
    cout << "1. Zaloguj"<<endl;
    cout << "2. Zarejestruj"<<endl;

    cout << "\n0. Zakoncz Program";
    cout << "\n\nTwoj Wybor: ";
};

int KsiazkaAdresowa::logowanieUzytkownika(){
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
        case ('1'):
        {
            cout <<endl<< "LOGOWANIE"<<endl;
            return logowanieUzytkownika(); //zwraca ID zalogowanego uzytkownika
            break;
        }
        case ('2'):
        {
            cout <<endl<< "REJESTRACJA"<<endl;
            rejestracjaUzytkownika();
            break;
        }


        case ('0'):
        {
            return 0;

        }
        default:
            cout <<endl<< "Niepoprawny wybor";
            Sleep(1500);
            break;
        }

    }
    while (wybor!=0);
};
