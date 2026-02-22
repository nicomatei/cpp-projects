/* 26.Se da, de la tastatura un numar natural k, de maxim 4 cifre. In fisierul numere.txt este
memorat un sir de maxim 10000 numere naturale distincte, cu cel mult 4 cifre fiecare,
separate prin spatiu. Se cere afisarea pe ecran a pozitiei pe care se va gasi numarul k in sirul
numerelor din fisier ordonat descrescator sau mesajul nu exista daca numarul k nu face parte
din sir.
Exemplu : daca fisierul numere.txt contine numerele : 26 2 5 30 13 45 62 7 79 iar k=13
atunci pe ecran se va afisa 6 */

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/22-02-26-numere.txt");
    int n, k, count = 0, notFound = 0;
    cin >> k;
    while (fin >> n)
    {
        if (k == n)
            notFound = 1;
        if (n > k)
            count++;
    }
    if (notFound == 0)
        cout << count + 1;
    else
        cout << "not found";
    fin.close();
    return 0;
}