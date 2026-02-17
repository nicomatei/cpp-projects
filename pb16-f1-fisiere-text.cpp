/* 16. Se citesc n numere din fisierul DATE.IN. Cate sunt mai mari decat zero,
cate egale cu zero si cate mai mici decat zero, precum si procentul
reprezentat de fiecare categorie din numarul total de numere. Aceasta
statistica se va scrie cat mai frumos in STATIST.OUT. */

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("in/17-02-26-date.in");
    ofstream fout("out/17-02-26-statist.out");
    int n, poz = 0, neg = 0, nul = 0;
    float a;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> a;
        if (a > 0)
            poz++;
        else if (a < 0)
            neg++;
        else
            nul++;
    }
    fout << poz << " nr poz. reprezentand " << 100.0 * poz / n << "% din total " << endl;
    fout << neg << " nr neg. reprezentand " << 100.0 * neg / n << "% din total " << endl;
    fout << nul << " nr nul reprezentand " << 100.0 * nul / n << "% din total " << endl;
    fin.close();
    fout.close();
    return 0;
}