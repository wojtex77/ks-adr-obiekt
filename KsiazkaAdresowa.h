#include <iostream>
#include <vector>
#include <windows.h>
#include <sstream>
#include <fstream>
#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    string nazwaPlikuZUzytkownikami;

    vector <Uzytkownik> uzytkownicy;
    int pobierzIdNowegoUzytkownika ();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();
    void dopiszUzytkownikaDoPliku(Uzytkownik uzytkownik);
    bool czyPlikJestPusty(fstream &plikTekstowy);


    string zamienDaneUzytkownikaNaLinieZDanymiOddzielonaPionowymiKreskami(Uzytkownik uzytkownik);
    string konwerjsaIntNaString(int liczba);

public:
    KsiazkaAdresowa ();
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
