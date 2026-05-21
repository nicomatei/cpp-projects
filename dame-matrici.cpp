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

void populeazaTablaInitiala(int tabla[8][8])
{
    // punem piesele pt player 1 = 🔵 si 2 = 🔴
    for (int i = 5; i < 8; i++)
        for (int j = 0; j < 8; j++)
            if (tabla[i][j] == 9)
                tabla[i][j] = 1;
    for (int i = 0; i < 3; i++)
        for (int j = 0; j < 8; j++)
            if (tabla[i][j] == 9)
                tabla[i][j] = 2;
}

bool canMove(int x1, int y1, int x2, int y2, int tabla[8][8], int playerMove)
{
    bool possibleMove = true;
    int direction = playerMove == 1 ? 1 : -1; // ternary operator - if playerMove == 1 then direction = 1, else direction = -1
    int opponent = playerMove == 1 ? 2 : 1;
    if (tabla[y2][x2] != 9)
    {
        possibleMove = false; // only move on black square
        cout << "pls only move on black square";
    }
    else if (tabla[y1][x1] != playerMove)
    {
        possibleMove = false; // blue can only move blue pieces, red can only move red pieces
        cout << "pls only move with your pieces";
    }
    else if (y1 - y2 == direction && abs(x1 - x2) != 1)
    {
        possibleMove = false;
        cout << "pls learn how to play";
    }
    else if (y1 - y2 == 2 * direction && !(abs(x1 - x2) == 2 && tabla[y1 + direction][x1 + (x2 - x1) / 2] == opponent))
    {
        possibleMove = false;
        cout << "pls check the instructions manuals";
    }
    return possibleMove;
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

    populeazaTablaInitiala(tabla);
    // tabla[2][3] = 2;
    // tabla[3][4] = 1;

    // afisare
    afisare(tabla, linii, coloane);
    cout << endl;

    int playerMove = 1; // det a cui ii tura
    cout << "selecteaza piesa + spatiu + unde o muti (ex: e3 f4): " << endl;

    int c1 = 12;
    int c2 = 12;
    while (c1 > 0 && c2 > 0)
    {
        string moveFrom, moveTo;
        if (playerMove == 1)
            cout << endl
                 << "player 🔵: ";
        else
            cout << endl
                 << "player 🔴: ";
        cin >> moveFrom >> moveTo;
        int x1 = getLetterPoz(moveFrom[0]);
        int y1 = 8 - (moveFrom[1] - '0');
        int x2 = getLetterPoz(moveTo[0]);
        int y2 = 8 - (moveTo[1] - '0');

        if (canMove(x1, y1, x2, y2, tabla, playerMove))
        {
            swap(tabla[y1][x1], tabla[y2][x2]);

            // daca sare peste o dama adversara pe diagonala o manana
            if (playerMove == 1)
            {
                if (tabla[y1 - 1][x1 + 1] == 2 && tabla[y2][x2] == playerMove && tabla[y2][x2] == tabla[y1 - 2][x1 + 2])
                {
                    tabla[y1 - 1][x1 + 1] = 9;
                }
                if (tabla[y1 - 1][x1 - 1] == 2 && tabla[y2][x2] == playerMove && tabla[y2][x2] == tabla[y1 - 2][x1 - 2])
                {
                    tabla[y1 - 1][x1 - 1] = 9;
                }
            }
            if (playerMove == 2)
            {
                if (tabla[y1 + 1][x1 + 1] == 1 && tabla[y2][x2] == playerMove && tabla[y2][x2] == tabla[y1 + 2][x1 + 2])
                {
                    tabla[y1 + 1][x1 + 1] = 9;
                }
                if (tabla[y1 + 1][x1 - 1] == 1 && tabla[y2][x2] == playerMove && tabla[y2][x2] == tabla[y1 + 2][x1 - 2])
                {
                    tabla[y1 + 1][x1 - 1] = 9;
                }
            }

            afisare(tabla, linii, coloane);
            if (playerMove == 1)
                playerMove = 2;
            else
                playerMove = 1;
        }
        cout << endl;

        // verif daca mai sunt piese de ambele culori
        c1 = 0, c2 = 0;
        for (i = 1; i < 8; i++)
            for (j = 1; j < 8; j++)
            {
                if (tabla[i][j] == 1)
                {
                    c1++;
                }
                if (tabla[i][j] == 2)
                {
                    c2++;
                }
            }
        // verif daca piesele ramase mai pot fi mutate (daca nu atunci end game)
    }
    if (c2 == 0)
        cout << endl
             << "WINNER IS 🔵" << endl;
    else
        cout << endl
             << "WINNER IS 🔴" << endl;

    return 0;
}