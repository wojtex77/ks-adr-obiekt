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

public:
    AdresatMenedzer(string nazwaPlikuZAdresatami) : plikZAdresatami(nazwaPlikuZAdresatami) {};
    void dodawanieAdresata(int idUzytkownika);
    void wypiszWszystkichAdresatowUzytkownika(int idUzytkownika);
    void wczytajAdresatowZPliku();


};

#endif // ADRESATMENEDZER
