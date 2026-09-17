#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("matrici-nr-nat.in/in");

    // verif daca exista linii in matricea A m*n cu aceeasi suma
    int k, i, j, m, n, s, a[101][101];
    for (i = 1; i <= m; i++)
        for (j = 1; j <= n; j++)
            fin >> a[i][j];
    for (i = 1; i <= m; i++)
    {
        s = 0;
        for (j = 1; j <= n; j++)
            s = s + a[i][j];
        a[i][0] = s;
    }
    int exista = 0;
    for (i = 1; i <= m; i++)
        for (k = i + 1; k <= m; k++)
            if (a[i][0] == a[k][0])
                exista = 1;
    if (exista == 1)
        cout << "exista" << endl;
    else
        cout << "nu exista" << endl;
    return 0;
}