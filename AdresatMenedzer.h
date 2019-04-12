#ifndef ADRESATMENEDZER_H
#define ADRESATMENEDZER_H

#include "Adresat.h"
#include "PlikZAdresatami.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class AdresatMenedzer
{
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

    int podajIdWybranegoAdresata();

    Adresat podajDaneNowegoAdresata();
    int pobierzIdNowegoAdresata();

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika)
    {
        adresaci=plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodawanieAdresata();
    int usunAdresata();
    void wypiszWszystkichAdresatowUzytkownika();


};

#endif // ADRESATMENEDZER
