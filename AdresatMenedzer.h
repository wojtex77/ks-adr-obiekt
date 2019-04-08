#ifndef ADRESATMENEDZER.H
#define ADRESATMENEDZER.H

#include "Adresat.h"
#include "PlikZAdresatami.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    PlikZAdresatami plikZAdresatami;
    Adresat podajDaneNowegoAdresata();
    int pobierzIdNowegoAdresata();
    const int ID_ZALOGOWANEGO_UZYTKOWNIKA;

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami, int idZalogowanegoUzytkownika) : plikZAdresatami(nazwaPlikuZAdresatami), ID_ZALOGOWANEGO_UZYTKOWNIKA(idZalogowanegoUzytkownika){
    adresaci=plikZAdresatami.wczytajAdresatowZPliku(ID_ZALOGOWANEGO_UZYTKOWNIKA);
    };
    void dodawanieAdresata();
    void wypiszWszystkichAdresatowUzytkownika();


};

#endif // ADRESATMENEDZER
