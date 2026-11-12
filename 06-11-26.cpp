/*
mod info bac 2009 varianta 26
sub iii
4.
a) stergerea elem v de i, v de i+1, ..., v de j din tabloul v cu n elemente
b) utilizati fct sterge a.i. intr un nr citi din fisier sa nu mai fie doua elem alaturate egale
*/

#include <iostream>
#include <fstream>
using namespace std;

void sterge(int v[], int &n, int i, int j)
// tablourile (vectori sau matrici) se transmit automat prin adresa
{
    int indice = i;
    for (int k = j + 1; k <= n; k++)
    {
        v[indice] = v[k];
        indice++;
    }
    n -= j - i + 1;
}

int main()
{
    ifstream f("sir-vector.in");
    int v[101], n;
    f >> n;
    for (int i = 1; i <= n; i++)
        f >> v[i];
    int i = 1;
    while (i <= n)
    {
        int j = i;
        while (j <= n && v[j] == v[i])
            j++;
        if (j - i >= 1)
            sterge(v, n, i + 1, j);
        i++;
    }
    return 0;
}