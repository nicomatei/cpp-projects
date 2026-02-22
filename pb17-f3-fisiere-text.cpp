/* fisierul text numere.in contine mai multe linii, pe fiecare linie existand cate un sir de numere
naturale nenule cel mult egale cu 3000 si despartite prin cate un spatiu; fiecare linie se
termina cu numarul 0 (care nu face parte din sir) si contine cel putin 2 valori; sa se afiseze
pe ecran valoarea maxima din sirul care contine cele mai putine numere; in cazul in care
exista mai multe solutii se va afisa oricare din ele; */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/19-02-26-numere.in");
    int n, k = 0, maxTemp = 0, maxNr = 0, minSir = 0, count = 0;
    // count = nr de siruri totale
    // k = min sir temporar
    while (fin >> n)
    {
        count++;
        while (n != 0)
        {
            k++;
            if (n > maxTemp)
                maxTemp = n;
            fin >> n;
        }
        if (count == 1)
            minSir = k;
        if (k < minSir)
        {
            maxNr = maxTemp;
            minSir = k;
        }
        else if (k == minSir && maxNr < maxTemp)
            maxNr = maxTemp;
        k = 0;
        maxTemp = 0;
    }
    cout << maxNr;
    fin.close();
    return 0;
}