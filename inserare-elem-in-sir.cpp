// fiind dat un vector v cu n elemente, sa se insereze valoarea val in pozitia poz in sir

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/sir-vector.in");
    int n, val, poz;
    fin >> n;
    int v[n + 2];
    cout << "val = ";
    cin >> val;
    cout << endl
         << "poz = ";
    cin >> poz;
    cout << endl;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = n; i >= poz; i--)
        v[i + 1] = v[i];
    v[poz] = val;
    n++;
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}