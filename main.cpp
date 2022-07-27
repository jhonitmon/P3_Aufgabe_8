#include <iostream>
#include <time.h>

using namespace std;

const int BREITE = 5;
const int HOEHE = 5;
int array[BREITE][HOEHE];
int spalte;

void fuelleMitNullen(int arr[BREITE][HOEHE]){
    for (int i = 0;i < HOEHE; i++){
        for (int j = 0;j < BREITE; j++){
            arr[i][j] = 0;
        }
    }

}

void gebeArrayAus(int arr[BREITE][HOEHE]) {
    cout << endl;
    cout << " |";
    for (int i = 0; i < BREITE; i++) {
        cout << " " << i + 1;
    }
    cout << endl << "-+";
    for (int i = 0; i < BREITE; i++) {
        cout << "--";
    }

    cout << endl;
    for (int i = 0;i < HOEHE; i++){
        cout << i + 1 << "|";
        for (int j = 0;j < BREITE; j++){
            cout << " " << arr[i][j];
        }
        cout << endl;
        }
}

bool istPunktImFeld(int x, int y) {
    if (x <= BREITE && y <= HOEHE) {
        //cout << "true" << endl;
        return true;
    } else {
        //cout << "false" << endl;
        return false;
    }
}

void aendereWert(int x, int y, int a) {
    if (istPunktImFeld(x,y) == 1) {
        //cout << "Richtig";
        array[y-1][x-1] = a;

    } else {
        cout << "Stelle ist nicht gueltig!" << endl;
    }
}

int steineInSpalte(int spalte) {
    int counter = 0;
    for (int i = 0;i < BREITE; i++){
        if (array[i][spalte - 1] != 0) {
            counter++;
            //cout << counter;
        } else {
            continue;
        }
    }
    return counter;
}

void werfeInSpalte (int spalte, int spieler) {
    int y = HOEHE - steineInSpalte(spalte);
    aendereWert(spalte , y, spieler);
}

int main()
{

    fuelleMitNullen(array);
    gebeArrayAus(array);
//    cout << "Bitte geben sie eine Spalte ein: ";
//    cin >> spalte;
//    cout << endl;
    werfeInSpalte(1,1);
    werfeInSpalte(2,2);
    werfeInSpalte(1,1);
    werfeInSpalte(1,1);
    werfeInSpalte(5,2);
    gebeArrayAus(array);


//    fuelleMitNullen(array);
//    gebeArrayAus(array);
//    int count = 0;
//    int spieler;
//    while (true) {
//        count++;
//        cout << count << " test " << count % 2 << endl;
//        if (count % 2 == 1){
//            spieler = 1;
//            cout << "Spieler " << spieler << ", bitte geben sie eine Spalte ein: ";
//            cin >> spalte;
//            cout << endl;
//            werfeInSpalte(spalte,spieler);
//            gebeArrayAus(array);
//            continue;
//        } else {
//            spieler = 2;
//            cout << "Spieler " << spieler << ", bitte geben sie eine Spalte ein: ";
//            cin >> spalte;
//            cout << endl;
//            werfeInSpalte(spalte,spieler);
//            gebeArrayAus(array);
//            continue;
//        }

//    }

    return 0;

}
