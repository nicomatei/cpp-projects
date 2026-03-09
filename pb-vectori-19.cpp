// permutati cu k pozitii elementele sirului

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/09-02-26-vector19.in");
    int n, k;
    fin >> n;
    cout << "dati nr de permutatii: ";
    cin >> k;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    fin.close();
    for (int j = 1; j <= k; j++)
    {
        int temp = v[1];
        for (int i = 1; i <= n - 1; i++)
            v[i] = v[i + 1];
        v[n] = temp;
    }
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}