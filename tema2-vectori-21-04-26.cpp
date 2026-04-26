// Se citește n – număr natural, apoi un șir de n numere naturale de maxim 7 cifre.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/sir-vector-nat.in");
    int n, v[101];
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];

    // a) Afișați tripletele de elemente alăturate care sunt în ordine strict crescătoare
    cout << "triplete de elemente alaturate in ordine strict crescatoare sunt: " << endl;
    int triplet = 0;
    for (int i = 1; i <= n; i++)
        if (v[i] < v[i + 1] && v[i + 1] < v[i + 2])
        {
            cout << v[i] << " " << v[i + 1] << " " << v[i + 2] << endl;
            triplet++;
        }
    if (triplet == 0)
        cout << "nu sunt" << endl;
    cout << endl;

    // b) Afișați perechile de elemente alăturate din vector care au împreună suma cifrelor mai mare decat 10.
    cout << "perechi de elemente alaturate care au impreuna suma cifrelor > 10: " << endl;
    int perechi = 0;
    for (int i = 1; i < n; i++)
    {
        int a = v[i], b = v[i + 1], sa = 0, sb = 0;
        while (a > 0)
        {
            sa = sa + a % 10;
            a = a / 10;
        }
        while (b > 0)
        {
            sb = sb + b % 10;
            b = b / 10;
        }
        if (sa + sb > 10)
        {
            cout << v[i] << " si " << v[i + 1] << endl;
            perechi++;
        }
    }
    if (perechi == 0)
        cout << "nu sunt" << endl;
    cout << endl;

    // c) Afișați perechile de elemente alăturate cu proprietatea că ultima cifră a primului număr din pereche este egală cu prima cifră a celui de-al doilea număr
    cout << "perechi de elemente alaturate unde ultima cifra a primului nr = prima cifra a celui de-al doilea nr: " << endl;
    perechi = 0;
    for (int i = 1; i < n; i++)
    {
        int b = v[i + 1];
        while (b > 9)
        {
            b = b / 10;
        }
        if (v[i] % 10 == b)
        {
            cout << v[i] << " si " << v[i + 1] << endl;
            perechi++;
        }
    }
    if (perechi == 0)
        cout << "nu sunt" << endl;
    cout << endl;

    fin.close();
    return 0;
}