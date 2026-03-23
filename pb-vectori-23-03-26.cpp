/* date.in contine n, apoi n nr nat
a) citire si numarare in vector si tiparim vectorii pe ecran - cate 7 pe rand
b) det min si pe ce poz apare
c) afis primu nr par si ultimu nr par
d) scrieti sirul si sortati sirul crescator dupa nr de divizori
e) daca n este par inserati la mijloc k elemente de valoare 0 (k dat de la tastatura) */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/vectori-23-03-26-date.in");
    int n, v[101], vmin = 100000, poz = 0, prpar = 0, ultpar = 0;
    // a
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= n; i++)
    {
        cout << v[i] << " ";
        if (i % 7 == 0)
            cout << endl;
    }
    cout << endl;
    // b
    for (int i = 1; i <= n; i++)
        if (v[i] < vmin)
            vmin = v[i];
    cout << "Minimul este: " << vmin << endl;
    cout << " Pozitiile in care apare minimul in sir sunt: ";
    for (int i = 1; i <= n; i++)
        if (v[i] == vmin)
            cout << i << " ";
    cout << endl;
    // c
    int existaPare = 0;
    for (int i = 1; i <= n && existaPare == 0; i++)
    {
        if (v[i] % 2 == 0)
        {
            prpar = i;
            existaPare = 1;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        if (v[i] % 2 == 0)
        {
            ultpar = v[i];
        }
    }
    if (existaPare)
        cout << "Pozitia primului numar par este: " << prpar << " ,iar pozitia ultimului par este: " << ultpar << endl;
    else
        cout << "Nu exista numere pare in sir" << endl;
    // d
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            /// calculam numarul de divizori pentru v[i] in nri
            int nri = 0;
            for (int d = 1; d <= v[i]; d++)
                if (v[i] % d == 0)
                    nri++;
            /// calculam numarul de divizori pentru v[j] in nrj
            int nrj = 0;
            for (int d = 1; d <= v[j]; d++)
                if (v[j] % d == 0)
                    nrj++;
            if (nri > nrj)
            {
                int aux = v[i];
                v[i] = v[j];
                v[j] = aux;
            }
        }
    cout << "\nSirul orodonat crescator dupa nr de divizori este: \n";
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
}