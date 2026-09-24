#include <iostream>
using namespace std;

// Sa se scrie un subprogram care verifica daca un numar natural este deosebit (exista un alt numar
// m natural cu proprietatea: n=m+Sumacifre(m) )

int SumaCifre(int n)
{
    int s = 0;
    while (n)
    {
        s += n % 10;
        n /= 10;
    }
    return s;
}

int eDeosebit(int n)
{
    int m = n - 1;
    while (m > 0)
    {
        if (m + SumaCifre(m) == n)
            return 1;
        m--;
    }
    return 0;
}

int main()
{
    int n;
    cout << "dati nr pt verificarea proprietatii de DEOSEBIT: ";
    cin >> n;
    if (eDeosebit(n))
        cout << "da";
    else
        cout << "nu";
    return 0;
}