#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // Se citește n – număr natural, apoi un șir de n numere naturale de maxim 7 cifre.
    ifstream fin("in/vector210426.in");
    int n, v[101];
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    fin.close();
    // a) Să se afișeze, pentru fiecare număr în parte, toți divizorii săi proprii sau mesajul ”numarul ... este prim”, după caz.
    for (int i = 1; i <= n; i++)
    {
        int d = 0;
        cout << "Divizorii numarului " << v[i] << " sunt: ";
        for (int j = 2; j < v[i]; j++)
            if (v[i] % j == 0)
            {
                cout << j << " ";
                d++;
            }
        if (d == 0)
            cout << "numarul " << v[i] << " este prim";
        cout << endl;
    }
    // b) Să se determine câte numere-palindrom există în șir (un număr este palindrom dacă el coincide cu oglinditul său)
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        int ogl = 0, c = v[i];
        while (c)
        {
            ogl = ogl * 10 + c % 10;
            c /= 10;
        }
        if (ogl == v[i])
            p++;
    }
    cout << "Numarul de numere-palindrom este: " << p << endl;
    // c) Să se calculeze și să se afișeze CMMDC a două câte două numere alăturate din șir.
    for (int i = 1; i < n; i++)
    {
        int a = v[i], b = v[i + 1];
        while (a != b)
            if (a > b)
                a -= b;
            else
                b -= a;
        cout << "CMMDC dintre " << v[i] << " si " << v[i + 1] << " este: " << a << endl;
    }
    // d) Să se calculeze CMMDC al tuturor numerelor din șir.
    int cmmdc = v[1];
    for (int i = 2; i <= n; i++)
    {
        int a = cmmdc, b = v[i];
        while (a != b)
            if (a > b)
                a -= b;
            else
                b -= a;
        cmmdc = a;
    }
    cout << "CMMDC al tuturor numerelor din șir este: " << cmmdc << endl;
    // e) Să se transforme șirul în memorie prin inversarea valorilor lui:
    // Șirul 303 7 100 888 sa devina 888 100 7 303.
    for (int i = 1; i <= n / 2; i++)
    {
        int aux = v[i];
        v[i] = v[n - i + 1];
        v[n - i + 1] = aux;
    }
    cout << "Șirul inversat este: ";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    cout << endl;
    return 0;
}
