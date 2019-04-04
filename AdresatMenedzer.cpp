#include "AdresatMenedzer.h"

void AdresatMenedzer::dodawanieAdresata(int idUzytkownika)
{
    Adresat adresat;
    system("cls");
    string temp;

    adresat.UstawIdUzytkownika(idUzytkownika);
    adresat.UstawIdAdresata(pobierzIdNowegoAdresata());
    cout << " >>> PODAJ DANE ADREATA <<<" << endl;
    cout << "---------------------------" << endl;

    cout << "Podaj imie: ";
    cin >> temp;
    adresat.UstawImie(temp);
    cout << "Podaj nazwisko: ";
    cin >> temp;
    adresat.UstawNazwisko(temp);
    cout << "Podaj numer telefonu: ";
    cin >> temp;
    adresat.UstawNumerTelefonu(temp);
    cout << "Podaj email: ";
    cin >> temp;
    adresat.UstawEmail(temp);
    cout << "Podaj adres: ";
    cin >> temp;
    adresat.UstawAdres(temp);
    adresaci.push_back(adresat);
};

int AdresatMenedzer::pobierzIdNowegoAdresata()
{
    int najwyzszeId=1;
    if (adresaci.empty())
        return najwyzszeId;
    else
    {
        for (int i=0; i<adresaci.size(); i++)
        {
            int temp=adresaci[i].pobierzIdAdresata();
            if (temp>najwyzszeId)
                najwyzszeId=temp;
        }
    }
    najwyzszeId++;
    return najwyzszeId;
};
