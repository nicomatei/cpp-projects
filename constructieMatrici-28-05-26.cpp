// sa se citeasca dimensiunile m, n, ale unei matrici, apoi sa se completeze astfel:

#include <iostream>
using namespace std;

bool prim(int nr)
{
    bool ePrim = true;
    for (int i = 2; i <= nr / 2; i++)
        if (nr % i == 0)
            ePrim = false;
    return ePrim;
}
int main()
{
    // 1.completare pe linii cu nr naturale 0, 1, 2...
    int m, n, nr = 0;
    cin >> m >> n;
    int a[m][n], p[n][n];
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            a[i][j] = nr;
            nr++;
        }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 2.completare pe coloane cu nr naturale 0, 1, 2...
    nr = 0;
    for (int j = 0; j < n; j++)
        for (int i = 0; i < m; i++)
        {
            a[i][j] = nr;
            nr++;
        }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 3.patratele perf la 0, 1, 2..., de la coltul din st jos pana in dr sus.
    nr = 0;
    for (int i = m - 1; i >= 0; i--)
        for (int j = n - 1; j >= 0; j--)
        {
            a[i][j] = nr * nr;
            nr++;
        }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 4.nr pare nedivizibile cu 3
    nr = 0;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            while (nr % 3 == 0)
                nr += 2;
            a[i][j] = nr;
            nr += 2;
        }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 5.Cu nr prime pe linii
    nr = 2;
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
        {
            while (!prim(nr))
                nr++;
            a[i][j] = nr;
            nr++;
        }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 6. matrice patratica A n*n. sa aiba pe diagonale doar 0,
    // in partea N si S sa aiba 1 si in E si V sa aiba 2
    cout << "n = " << n << endl;
    // int p[n][n];
    for (int i = 0; i < n; i++)
    {
        p[i][i] = 0;
        p[i][n - i + 1] = 0;
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << p[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 7. se cit x natural. contstr matrice cu cif lui x pe coloane

    return 0;
}
