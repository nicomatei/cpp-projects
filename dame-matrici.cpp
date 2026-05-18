#include <iostream>
using namespace std;

void printEmoji(int value)
{
    // cout << value << " ";
    // return;
    if (value == 0)
        cout << "⬜️";
    if (value == 9)
        cout << "⬛️";
    if (value == 1)
        cout << "🔵";
    if (value == 2)
        cout << "🔴";
}

void printLetter(int value)
{
    char l = char(96 + value);
    cout << l << " ";
}

int getLetterPoz(char l)
{
    return (l - '0') - 49;
}

void afisare(int tabla[8][8], int linii[8], int coloane[8])
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        cout << linii[i] << " ";
        for (j = 0; j < 8; j++)
            printEmoji(tabla[i][j]);
        cout << endl;
    }
    cout << "  ";
    for (j = 0; j < 8; j++)
        printLetter(coloane[j]);
}

int main()
{
    int tabla[8][8] = {0}, linii[8], coloane[8], i, j;

    // numerotare linii si coloane
    for (i = 0; i < 8; i++)
        linii[i] = 8 - i;
    for (j = 0; j < 8; j++)
        coloane[j] = j + 1;

    // tabla initiala 0 = ⬜️ si 9 = ⬛️
    for (i = 0; i < 8; i += 2)
        for (j = 1; j < 8; j += 2)
            tabla[i][j] = 9;
    for (i = 1; i < 8; i += 2)
        for (j = 0; j < 8; j += 2)
            tabla[i][j] = 9;

    // punem piesele pt player 1 = 🔵 si 2 = 🔴
    for (i = 5; i < 8; i++)
        for (j = 0; j < 8; j++)
            if (tabla[i][j] == 9)
                tabla[i][j] = 1;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 8; j++)
            if (tabla[i][j] == 9)
                tabla[i][j] = 2;

    // afisare
    afisare(tabla, linii, coloane);
    cout << endl;

    // string moveFrom = "d6";
    // string moveTo = "e5";

    string moveFrom, moveTo;
    cout << "player 🔵: " << endl;
    cout << "selecteaza piesa pe care vrei sa o muti (ex: e3): ";
    cin >> moveFrom;
    cout << "unde sa o muti (ex: f4): ";
    cin >> moveTo;
    cout << moveFrom << " -> " << moveTo << endl;
    int x1 = getLetterPoz(moveFrom[0]);
    int y1 = 8 - (moveFrom[1] - '0');
    int x2 = getLetterPoz(moveTo[0]);
    int y2 = 8 - (moveTo[1] - '0');
    if (tabla[y2][x2] == 9)
    {
        swap(tabla[y1][x1], tabla[y2][x2]);
        afisare(tabla, linii, coloane);
    }

    // swap(tabla[2][3], tabla[3][4]);
    // cout << endl;
    // afisare(tabla, linii, coloane);

    // int poz = getLetter('a');
    // cout << poz;
    // poz = getLetter('b');
    // cout << poz;
    // poz = getLetter('h');
    // cout << poz;
    return 0;
}