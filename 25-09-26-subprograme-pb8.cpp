#include <iostream>
using namespace std;

// Sa se scrie o functie care primeste ca parametru un numar natural n si returneaza cel mai
// apropiat numar prim strict mai mare decat acesta. Se va folosi o functie care verifica
// daca un numar este prim.

int ePrim(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int Apropiatul(int n)
{
    n++;
    while (!ePrim(n))
        n++;
    return n;
}

int main()
{
    int a;
    cin >> a;
    cout << Apropiatul(a);
    return 0;
}