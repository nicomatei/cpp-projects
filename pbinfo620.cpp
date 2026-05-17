// Se dă o matrice cu n linii şi m coloane şi elemente numere naturale.
// Ordonați descrescător elementele de pe fiecare coloană a matricei și apoi afișați matricea.

#include <iostream>
using namespace std;

int main()
{
    int n, m, a[101][101];
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> a[i][j];
    cout << endl;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int h = i + 1; h <= n; h++)
            {
                if (a[i][j] < a[h][j])
                    swap(a[i][j], a[h][j]);
            }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}