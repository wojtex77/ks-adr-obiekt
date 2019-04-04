#ifndef ADRESATMENEDZER.H
#define ADRESATMENEDZER.H

#include "Adresat.h"

#include <iostream>
#include <vector>
#include <windows.h>

using namespace std;

class AdresatMenedzer {
    vector <Adresat> adresaci;
    //PlikZAdresatami plikZAdresatami;
    //void wczytajAdresatowZPliku();
    Adresat podajDaneNowegoAdresata();
    int pobierzIdNowegoAdresata();

public:
    //AdresatMenedzer();
    void dodawanieAdresata(int idUzytkownika);
    void wypiszWszystkichAdresatowUzytkownika();


};

#endif // ADRESATMENEDZER
