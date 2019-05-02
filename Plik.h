#ifndef PLIK_H
#define PLIK_H

#include <fstream>

using namespace std;

class Plik {
public:
    bool czyPlikJestPusty(fstream *plikTekstowy);
};
#endif // PLIK_H
