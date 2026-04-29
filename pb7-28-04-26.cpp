// 7. n elevi sunt înșirați pe un rând la ora de sport. Pentru fiecare elev se cunoaște înălțimea (în centimetri)
// a) Verificați dacă sunt cel puțin 2 elevi cu aceeași înălțime care să stea unul lângă celălalt. (mesaj DA/NU)
// b) Verificați dacă există un elev cu înălțimea maximă care să stea lângă unul de înălțime minimă (mesaj DA/NU)
// c) Ordonați elevii descrescător după înălțime. Verificați câți elevi au rămas în același loc după ordonare. (nu și-au schimbat locul în șir)
// d) Afișați fiecare înălțime și numărul de elevi cu acea înălțime
// e) Elevii cu înălțimea maximă și cei cu înălțimea minimă pleacă. Afișați înălțimile elevilor rămași.

#include <iostream>
using namespace std;

int main()
{
    int n, v[101];
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    int ok = 0;
    for (int i = 1; i < n; i++)
        if (v[i] == v[i + 1])
            ok = 1;
    if (ok)
        cout << "da, sunt 2 elevi de aceeasi inaltime care stau unul langa altul" << endl;
    int poz[101];
    for (int i = 1; i <= n; i++)
        poz[i] = i;
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i] > v[j])
            {
                swap(v[i], v[j]);
                swap(poz[i], poz[j]);
            }
    cout << "\nSirul dupa sortare este:\n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    int k = 0;
    for (int i = 1; i <= n; i++)
        if (poz[i] == i)
        {
            k++;
        }
    cout << "\nSunt " << k << " elevi care au ramas pe loc dupa sortare\n";
    int fr[250] = {0};
    for (int i = 1; i <= n; i++)
        fr[v[i]]++;
    for (int i = 120; i < 249; i++)
        if (fr[i])
            cout << "\nSunt " << fr[i] << " cu inaltimea " << i << endl;
    int min = v[1];
    for (int i = 1; i <= n; i++)
        if (min < v[i])
            min = v[i];
    int i = 1;
    while (i <= n)
        if (v[i] == min)
        {
            for (int j = i; j <= n; j++)
                v[j] = v[j + 1];
            n--;
        }
        else
            i++;
    cout << "\nDupa plecarea din sir a elevilor";
    return 0;
}