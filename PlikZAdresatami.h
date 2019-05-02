#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"
#include "Plik.h"

using namespace std;

class PlikZAdresatami: public Plik
{

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami="temp.txt";
    int idOstatniegoAdresata;

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int edytujPlikTekstowyAdresatow(int idAdresata, string liniaZDanymiAdresataOddzielonePionowymiKreskami);


    string zamienDaneAdresatowNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);



public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {idOstatniegoAdresata=0;};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void zapiszWszystkichAdresatowDoPliku(vector <Adresat> Adresaci);
    int pobierzIdOstatniegoAdresata();
    void usunWybranegoAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneEdytowanegoAdresata(Adresat adresat);

};

#endif
