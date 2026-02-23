
#include <iostream>
#include <fstream>
using namespace std;
/* 5. Fişierul text numere.in conține: pe prima linie un număr natural nenul n (n<1000) iar pe a
doua linie n numere naturale cu cel mult 9 cifre fiecare, despărțite prin câte un spațiu. Să se
afişeze pe ecran, separate prin câte un spațiu, numerele de pe a doua linie din fişier care încep
şi se termină cu aceeaşi cifră. */
int main()
{
    ifstream fin("in/23-02-26-numere.in");
    int n, k, uc, cop;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> k;
        cop = k;
        uc = cop % 10;
        while (cop > 9)
        {
            cop = cop / 10;
        }
        if (cop == uc)
        {
            cout << k << " ";
        }
    }
    fin.close();
    return 0;
}