#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;


int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    cout << ksiazkaAdresowa.menuUzytkownika(ksiazkaAdresowa.menuLogowania());

    return 0;
}
