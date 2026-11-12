#include <iostream>
#include <fstream>
using namespace std;

// fisa 2 prelucrare matrici - pe grupul clasei

void CitireMatr(int a[][31], int &n, int &m) // 1
{
    ifstream f("in/matrici-nr-intregi.in");
    f >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            f >> a[i][j];
    f.close();
}
void AfisareMatr(int a[][31], int &n, int &m) // 1
{
    cout << "Matricea este: \n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
}

void pctA(int a[][31], int n, int m) // 1a
{
    cout << "cele 4 colturi sunt: ";
    cout << a[1][1] << " " << a[1][m] << " " << a[n][1] << " " << a[n][m] << endl;
}

// 4
// void elemPoz(int a[][31], int n, int m)
// {
//     int indice=
// }

int main()
{
    int a[31][31], n, m;
    CitireMatr(a, n, m);
    AfisareMatr(a, n, m);
    pctA(a, n, m);

    return 0;
}