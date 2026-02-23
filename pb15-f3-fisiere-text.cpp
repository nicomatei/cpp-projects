/* 15.Fişierul text numere.in conține cel mult 10000 de numere naturale cu maxim 9 cifre fiecare,
separate prin câte un spațiu. Cel puțin unul dintre numere este palindrom. Să se afişeze, în
fişierul text numere.out, pe linii separate, cel mai mare număr palindrom din fişier şi numărul
său de apariții în fişier. */

#include <iostream>
#include <fstream>

using namespace std;
int main()
{
    ifstream f("in/23-02-26-nnumere.in");
    ofstream g("out/23-02-26-numere.out");
    int n, maxim = 0, nrap;
    while (f >> n)
    {
        /// verific daca n e palindrom
        int cop = n, ogl = 0;
        while (cop)
        {
            ogl = ogl * 10 + cop % 10;
            cop = cop / 10;
        }
        if (n == ogl) /// n este palindrom
            if (n > maxim)
            {
                maxim = n;
                nrap = 1;
            }
            else if (maxim == n)
            {
                nrap++;
            }
    }
    g << maxim << " " << nrap;
    f.close();
    g.close();
}