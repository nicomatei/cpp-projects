// Se dă o matrice cu n linii şi m coloane şi elemente numere naturale.
// Determinați indicele liniei care conține număr maxim de elemente pare.
// Dacă există mai multe linii cu număr maxim de elemente pare, se vor afișa toți indicii,
// în ordine crescătoare.
// Programul citește de la tastatură numerele n şi m, iar apoi n*m numere naturale,
// separate prin spaţii, reprezentând elementele matricei, linie cu linie.
// Programul afișează pe ecran indicii liniilor cu număr maxim de elemente pare,
// în ordine crescătoare, separați prin câte un spaţiu.

#include <iostream>
using namespace std;

int main()
{
    int n, m, a[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    for (int i = 2; i <= n; i++)
    {
        a[i][0] = 0;
    }
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (a[i][j] % 2 == 0)
                a[i][0]++;
        }
    int maxpar = 0;
    for (int i = 1; i <= n; i++)
        if (a[i][0] > maxpar)
            maxpar = a[i][0];
    for (int i = 1; i <= n; i++)
        if (a[i][0] == maxpar)
            cout << i << " ";
    return 0;
}
