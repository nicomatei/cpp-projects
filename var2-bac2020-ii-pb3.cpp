// Variabilele i şi j sunt de tip întreg, iar variabila a memorează un tablou bidimensional cu 5 linii şi 7
// coloane, numerotate începând de la 0, cu elemente numere întregi, inițial toate egale cu 1.
// Fără a utiliza alte variabile decât cele menționate, scrieţi o secvenţă de instrucţiuni
// prin care se transformă în memorie tabloul, astfel încât orice element aflat pe prima
// linie sau pe prima coloană să aibă valoarea 1 şi oricare alt element din tablou să fie
// egal cu ultima cifră a sumei celor două elemente alăturate lui, aflate pe aceeaşi linie dar
// pe coloana din stânga, respectiv pe aceeaşi coloană, dar pe linia anterioară.

#include <iostream>
using namespace std;

int main()
{
    int a[5][7], i, j;
    for (i = 0; i < 5; i++)
        a[i][0] = 1;
    for (j = 0; j < 7; j++)
        a[0][j] = 1;
    for (i = 1; i < 5; i++)
    {
        for (j = 1; j < 7; j++)
            a[i][j] = (a[i][j - 1] + a[i - 1][j]) % 10;
    }
    for (i = 0; i < 5; i++)
    {
        for (j = 0; j < 7; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    return 0;
}