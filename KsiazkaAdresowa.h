#include <iostream>
#include <vector>
#include <windows.h>

#include "Uzytkownik.h"

using namespace std;

class KsiazkaAdresowa
{
    int idZalogowanegoUzytkownika;
    int idOstatniegoAdresata;
    int idUsunietegoAdresata;

    vector <Uzytkownik> uzytkownicy;
    int pobierzIdNowegoUzytkownika ();
    bool czyIstniejeLogin(string login);
    Uzytkownik podajDaneNowegoUzytkownika();


public:
    void rejestracjaUzytkownika();
    void wypiszWszystkichUzytkownikow();

};
