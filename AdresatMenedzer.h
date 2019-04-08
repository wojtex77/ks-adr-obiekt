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
    adresaci=plikZAdresatami.wczytajAdresatowZPliku(idZalogowanegoUzytkownika);
    };
    void dodawanieAdresata();//(int idUzytkownika);
    void wypiszWszystkichAdresatowUzytkownika();//(int idUzytkownika);
    void wczytajAdresatowZPliku();//(int idUzytkownika);


};

#endif // ADRESATMENEDZER
