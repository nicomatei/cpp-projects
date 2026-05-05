// 16.Fişierul text NR.TXT conţine numere naturale, fiecare număr având cel mult 4 cifre.
// Scrieţi un program C/C++ care citeşte numerele din fişierul NR.TXT şi afişează pe ecran,
// separate prin câte un spaţiu, în ordine descrescătoare, toate numerele din fişier care
// au cel mult 2 cifre. Dacă fişierul nu conţine astfel de numere se va afişa pe ecran
// mesajul NU EXISTA

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n = 1, v[101], x;
    ifstream fin("in/vectori222.in");
    while (fin >> x)
    {
        v[n] = x;
        n++;
    }
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
            if (v[i] < v[j])
                swap(v[i], v[j]);
    bool exista = false;
    for (int i = 1; i <= n; i++)
        if (v[i] < 100)
        {
            cout << v[i] << " ";
            exista = true;
        }
    if (!exista)
        cout << "nu exista";
    return 0;
}