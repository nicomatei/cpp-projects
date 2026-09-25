#include <iostream>
#include <fstream>
using namespace std;

// Un numar care este divizibil cu suma cifrelor lui, este numar Niven. Verificati care dintre
// numerele citite dintr-un fisier text sunt numere Niven.

int sumCif(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int main()
{
    ifstream f("in/vectori111.in");
    int n;
    while (f >> n)
        if (n % sumCif(n) == 0)
            cout << n << " ";
    return 0;
}