#ifndef ADRESAT_H
#define ADRESAT_H

#include <string>

using namespace std;

class Adresat
{
    int idAdresata, idUzytkownika;
    string imie, nazwisko, numerTelefonu, email, adres;

public:
    Adresat(int idAdresata, int idUzytkownika, string imie,string nazwisko,
            string numerTelefonu, string email, string adres);
    Adresat();

    void UstawIdAdresata(int liczba);
    void UstawIdUzytkownika(int liczba);
    void UstawImie(string tekst);
    void UstawNazwisko(string tekst);
    void UstawNumerTelefonu(string tekst);
    void UstawEmail(string tekst);
    void UstawAdres(string tekst);

    string pobierzImie ();
    string pobierzNazwisko ();
    string pobierzNumerTelefonu ();
    string pobierzEmail ();
    string pobierzAdres ();
    int pobierzIdAdresata();
    int pobierzIdUzytkownika();

};

#endif // ADRESAT
