// 3

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // c - afis elem care sunt unice in coloanele lor
    ifstream fin("in/matrici-nr-nat.in");
    int m, n, a[31][31], i, j;
    fin >> m >> n;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            fin >> a[i][j];
    bool exista = false;
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
        {
            // verif daca a[i][j] e unic pe coloana j
            int c = 0;
            for (int k = 1; k <= m; k++)
                if (a[k][j] == a[i][j])
                    c++;
            if (c == 1)
            {
                cout << a[i][j] << " ";
                exista = true;
            }
        }
    if (!exista)
        cout << "nu exista val unice pe col lor";
    cout << endl
         << endl;
    // d - sterge linia de la mijlocul matricii
    if (m % 2 == 0)
        cout << "nu exista linie mediana";
    else
    {
        int med = m / 2 + 1;
        for (i = med + 1; i <= m; i++)
            for (j = 1; j <= n; j++)
                a[i][j] = a[i + 1][j];
    }
    return 0;
}