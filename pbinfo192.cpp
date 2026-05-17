// Să se afișeze elementele de pe coloana din matrice cu suma elementelor maximă
// Fişierul de intrare sumcolmax.in conţine pe prima linie numerele n și m,
// iar următoarele n linii câte m numere întregi, reprezentând elementele matricei.
// Fişierul de ieşire sumcolmax.out va conţine 1 linii, cu n valori, separate prin spații,
// reprezentând elementele de pe coloana cu suma elementelor maximă

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/sumcolmax.in");
    ofstream fout("out/sumcolmax.out");
    // reading the matrice
    int n, m, a[101][101];
    fin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> a[i][j];

    // calculating the suma of the column
    int maxcolsum = -100, poz = 0;
    for (int j = 1; j <= m; j++)
    {
        for (int i = 1; i <= n; i++)
            a[0][j] += a[i][j];
        if (a[0][j] > maxcolsum)
        {
            maxcolsum = a[0][j];
            poz = j;
        }
    }

    for (int i = 1; i <= n; i++)
        fout << a[i][poz] << " ";
    fin.close();
    fout.close();
    return 0;
}