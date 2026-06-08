// Scrieți un singur program C++ pentru cerințele de mai jos:
// 1) Să se citească din fişierul DATE.IN două numere naturale m şi n, (1<=m, n<=50),
// apoi elementele unei matrici a cu m linii și n coloane, numere naturale. Tipăriți pe
// ecran matricea.
// 2) Înlocuiți cu 0 elementele care sunt puteri ale lui 2
// 3) Interschimbați prima linie cu ultima linie, a doua cu penultima etc. Tipăriți pe
// ecran matricea obținută.
// 4) Afişați numerele de ordine ale liniilor "munte". O linie este considerată "munte"
// dacă are elementele în ordine strict crescătoare. Mesaj dacă nu există.
// 5) Construiți matricea b cu aceleași dimensiuni ca matricea inițială, în care
// b[i][i]=suma cifrelor lui a[i][j]. Tipăriți pe ecran matricea b.
// 6) Verificați dacă n (numărul de coloane) este impar și are o valoare mai mare decât patru.
// Dacă da, ștergeți din matricea a cele 3 coloane din mijloc și afişați matricea modificată.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 1
    ifstream fin("in/matrici-nr-nat.in");
    int m, n, i, j, copieNr;
    fin >> m >> n;
    int a[m][n];
    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            fin >> a[i][j];
    cout << "Matricea 1:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 2
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            copieNr = a[i][j];
            while (copieNr % 2 == 0 && copieNr != 0)
                copieNr = copieNr / 2;
        }
        if (copieNr == 1 && a[i][j] != 1)
            a[i][j] = 0;
    }
    cout << "Matricea 2:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 3

    int copieM = m - 1;
    for (i = 0; i < copieM; i++)
    {
        for (j = 0; j < n; j++)
            swap(a[i][j], a[copieM][j]);
        copieM--;
    }
    cout << "Matricea 3:" << endl;
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 4
    bool ordonat = true;
    for (i = 0; i < m; i++)
    {
        ordonat = true;
        for (j = 0; j < n; j++)
        {
            if (a[i][j] > a[i + 1][j + 1])
                ordonat = false;
        }
        if (ordonat)
            cout << "linia " << i + 1 << " este munte" << endl;
    }
    return 0;
}