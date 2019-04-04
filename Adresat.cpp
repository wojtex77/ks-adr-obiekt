#include "Adresat.h"


void Adresat::UstawIdAdresata(int liczba)
{
    idAdresata=liczba;
};
void Adresat::UstawIdUzytkownika(int liczba)
{
    idUzytkownika=liczba;
};


void Adresat::UstawImie(string tekst)
{
    imie=tekst;
};
void Adresat::UstawNazwisko(string tekst)
{
    nazwisko=tekst;
};
void Adresat::UstawNumerTelefonu(string tekst)
{
    numerTelefonu=tekst;
};
void Adresat::UstawEmail(string tekst)
{
    email=tekst;
};
void Adresat::UstawAdres(string tekst)
{
    adres=tekst;
};

string Adresat::pobierzImie ()
{
    return imie;
};
string Adresat::pobierzNazwisko ()
{
    return nazwisko;
};
string Adresat::pobierzNumerTelefonu ()
{
    return numerTelefonu;
};
string Adresat::pobierzEmail ()
{
    return email;
};
string Adresat::pobierzAdres ()
{
    return adres;
};

int Adresat::pobierzIdAdresata(){
    return idAdresata;
};
int Adresat::pobierzIdUzytkownika(){
    return idUzytkownika;
};
