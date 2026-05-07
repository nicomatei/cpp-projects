// Se dă un şir cu n elemente, numere naturale. Să se verifice dacă oglinditul primului element apare printre celelalte elemente ale șirului.
// Programul citește de la tastatură numărul n, iar apoi cele n elemente ale şirului, separate prin spaţii.
// Programul afișează pe ecran mesajul DA, dacă există în şir elemente egale cu oglinditul primului element, respectiv NU în caz contrar.
// 1 ≤ n ≤ 100 si elementele şirului vor avea cel mult 9 cifre

#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int v[n], i;
    for (i = 0; i < n; ++i)
        cin >> v[i];
    int ogl = 0;
    while (v[0] != 0)
    {
        ogl = ogl * 10 + v[0] % 10;
        v[0] /= 10;
    }
    v[0] = ogl;
    for (i = 1; i < n; ++i)
        if (v[i] == v[0])
        {
            cout << "DA";
            break;
        }
    if (i == n)
        cout << "NU";
    return 0;
}