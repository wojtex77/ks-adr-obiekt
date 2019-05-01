#ifndef PLIKZADRESATAMI_H
#define PLIKZADRESATAMI_H

#include <iostream>
#include <vector>
#include <fstream>

#include "Adresat.h"
#include "MetodyPomocnicze.h"

using namespace std;

class PlikZAdresatami
{

    const string NAZWA_PLIKU_Z_ADRESATAMI;
    string nazwaTymczasowegoPlikuZAdresatami="temp.txt";
    int idOstatniegoAdresata;

    int pobierzIdAdresataZDanychOddzielonychPionowymiKreskami(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void usunOdczytywanyPlik(string nazwaPlikuZRozszerzeniem);
    void zmienNazweTymczasowegoPlikuNaNazweOdczytywanegoPliku(string nazwaTymczasowegoPlikuZRozszerzeniem, string nazwaPlikuZRozszerzeniem);
    string pobierzLiczbe(string tekst, int pozycjaZnaku);
    int zwrocNumerLiniiSzukanegoAdresata(int idAdresata);


    bool czyPlikJestPusty(fstream *plikTekstowy);
    string zamienDaneAdresatowNaLinieZDanymiOddzielonaPionowymiKreskami(Adresat adresat);
    Adresat pobierzDaneAdresata(string daneJednegoAdresataOddzielonePionowymiKreskami);
    void edytujWybranaLinieWPliku(int numerEdytowanejLinii, string liniaZDanymiAdresataOddzielonePionowymiKreskami);



public:
    PlikZAdresatami(string nazwaPlikuZAdresatami) : NAZWA_PLIKU_Z_ADRESATAMI(nazwaPlikuZAdresatami) {idOstatniegoAdresata=0;};
    void dopiszAdresataDoPliku(Adresat adresat);
    vector <Adresat> wczytajAdresatowZPliku(int idZalogowanegoUzytkownika);
    void zapiszWszystkichAdresatowDoPliku(vector <Adresat> Adresaci);
    int pobierzIdOstatniegoAdresata();
    void usunWybranegoAdresata(int idUsuwanegoAdresata);
    void zaktualizujDaneEdytowanegoAdresata(Adresat adresat, int idEdytowanegoAdresata);

};

#endif
