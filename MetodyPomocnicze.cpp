#include "MetodyPomocnicze.h"

string MetodyPomocnicze::konwerjsaIntNaString(int liczba)
{
    ostringstream ss;
    ss << liczba;
    string str = ss.str();
    return str;
}

string MetodyPomocnicze::wczytajLinie(){
    cin.sync();
    string linia;
    getline(cin, linia);
    return linia;
}

char MetodyPomocnicze::wczytajZnak(){
    cin.sync();
    string wejscie;
    char znak = {0};
    while (1){
        getline(cin,wejscie);
        if (wejscie.length()==1)
        {
            znak=wejscie[0];
            break;
        }
        cout << "To nie jest pojedynczy znak "<<endl;
    }
    return znak;
}


int MetodyPomocnicze::konwersjaStringNaInt(string liczba)
{
    int liczbaInt;
    istringstream iss(liczba);
    iss >> liczbaInt;

    return liczbaInt;
}


int MetodyPomocnicze::wczytajLiczbeCalkowita()
{
    string wejscie = "";
    int liczba = 0;

    while (true)
    {
        getline(cin, wejscie);

        stringstream myStream(wejscie);
        if (myStream >> liczba)
            break;
        cout << "To nie jest liczba. Wpisz ponownie. " << endl;
    }
    return liczba;
}
