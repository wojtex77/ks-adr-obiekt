#include <iostream>
#include "KsiazkaAdresowa.h"

using namespace std;


int main()
{
    KsiazkaAdresowa ksiazkaAdresowa ("Uzytkownicy.txt");
    cout << ksiazkaAdresowa.menuLogowania();

    return 0;
}
