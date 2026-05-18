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
    if (value == 1)
        cout << "a ";
    if (value == 2)
        cout << "b ";
    if (value == 3)
        cout << "c ";
    if (value == 4)
        cout << "d ";
    if (value == 5)
        cout << "e ";
    if (value == 6)
        cout << "f ";
    if (value == 7)
        cout << "g ";
    if (value == 8)
        cout << "h ";
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
    // swap(tabla[2][3], tabla[3][4]);
    // cout << endl;
    // afisare(tabla, linii, coloane);

    return 0;
}