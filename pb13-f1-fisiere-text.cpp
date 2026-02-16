// 13. Se citesc n numere. Cate sunt pare, cate impare si cate au exact o
// cifra? Citire din INTRARE.TXT, afisare rezultate in IESIRE.TXT.

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("in/16-02-26-intrare.txt");
    ofstream fout("out/16-02-26-iesire.txt");

    int n, nr, par = 0, imp = 0, ocifra = 0;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> nr;
        if (nr % 2 == 0)
            par++;
        else
            imp++;
        if (nr == nr % 10)
            ocifra++;
    }
    fout << "sunt " << par << " nr pare si " << imp << " nr impare" << endl;
    fout << "sunt " << ocifra << " numere cu o singura cifra" << endl;

    fin.close();
    fout.close();
    return 0;
}