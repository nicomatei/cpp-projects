// Scrieţi un program C/C++ care citeşte de la tastatură un număr natural, n (n∈[2,20]), şi construieşte
// în memorie un tablou bidimensional cu n linii şi n coloane, având proprietăţile:
// • toate elementele situate pe diagonala secundară sunt nule;
// • fiecare linie conţine, începând cu diagonala secundară, de la dreapta la stânga, un şir strict crescător
// de numere consecutive, iar începând cu diagonala secundară, de la stânga la dreapta, tot un şir strict
// crescător de numere consecutive.
// Programul afişează pe ecran tabloul construit, fiecare linie a tabloului pe câte o linie a
// ecranului, cu elementele aflate pe aceeaşi linie separate prin câte un spaţiu.

#include <iostream>
using namespace std;

int main()
{
    int n, i, j, x;
    cin >> n;
    int a[n + 1][n + 1];
    // diagonala secundara (ds)
    for (i = 1; i <= n; i++)
        a[i][n - i + 1] = 0;
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n + 1; j++)
            a[i][j] = x;
        x++;
    }
    return 0;
}