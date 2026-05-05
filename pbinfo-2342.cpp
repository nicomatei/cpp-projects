// După ce au trecut sărbătorile, ca în fiecare an, Moș Crăciun a început să facă inventarul cadourilor rămase pentru anul următor.
// El are N cadouri și pe fiecare cadou este scris un număr natural. În fiecare an Moș Crăciun trebuie să noteze într-un carnețel
// cantitatea de fericire pe care o aduc aceste cadouri copiilor.
// Astfel el obține un număr foarte mare. Apoi el știe că numărul de divizori al acestui număr este cantitatea de fericire
// e care el trebuie să o scrie în carnețel. Ajutați-l pe Moș Crăciun să afle cantitatea de fericire a celor N cadouri.
// Deoarece acest număr este foarte mare voi trebuie sa aflați doar restul împărțirii la 1.000.000.007.

// n = cate nr sunt in sir
// tre sa inmultim toate nr si notam produsul lor cu p
// se cere sa aflam numarul de divizori ai lui p

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, v[101], p = 1;
    ifstream fin("in/pbinfo2342.in");
    ofstream fout("out/pbinfo2342.out");
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= n; i++)
        p = p * v[i];
    int nrdiv = 0;
    for (int d = 1; d <= p; d++)
        if (p % d == 0)
            nrdiv++;
    fout << "nr de div ai prod nr din sir este: " << nrdiv << endl;
    fin.close();
    fout.close();
    return 0;
}