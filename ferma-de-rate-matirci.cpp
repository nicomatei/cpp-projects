// tarcul cu n linii, m coloane
// 1 - in tar e o rata
// 0 - tarc gol

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/ferma.in");
    int n, m;
    fin >> n >> m;
    int a[n + 1][m + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            fin >> a[i][j];

    // 3. exista un rand fara nicio rata?
    for (int i = 1; i <= n; i++)
    {
        bool faraRate = true;
        for (int j = 1; j <= m; j++)
            if (a[i][j] == 1)
                faraRate = false;
        if (faraRate)
            cout << "randul " << i << endl;
    }
    cout << endl;

    // 5. exista 3 pozitii consecutive ocupate? afis randul daca da
    int exista;
    for (int i = 1; i <= n; i++)
    {
        bool exista3Consecutive = false;
        for (int j = 1; j <= m - 2; j++)
            if (a[i][j] == 1 && a[i][j + 1] == 1 && a[i][j + 2] == 1)
                exista3Consecutive = true;
        if (exista3Consecutive)
        {
            cout << "linia " << i << " contine grup de 3 consecutive";
            exista = true;
        }
        if (!exista)
            cout << "nu exita";
    }
    return 0;
}