#ifndef KSIAZKAADRESOWA_H
#define KSIAZKAADRESOWA_H
#include <iostream>
#include <windows.h>
#include "UzytkownikMenedzer.h"

using namespace std;

class KsiazkaAdresowa
{

    UzytkownikMenedzer uzytkownikMenedzer;

    void wyswietlMenuLogowania();
    int logowanieUzytkownika();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();


public:
    KsiazkaAdresowa(string nazwaPlikuZUzytkownikami) : uzytkownikMenedzer(nazwaPlikuZUzytkownikami) {
        uzytkownikMenedzer.wczytajUzytkownikowZPliku();
        };
    int menuLogowania();

};

#endif
