#include <iostream>
using namespace std;

// sa se scrie un subprogram care verifica daca n este prim
// sa se afiseze primele k numere prime

int ePrim(int n)
{
    if (n < 2)
        return 0;
    for (int i = 2; i * i <= n; i++)
        if (n % i == 0)
            return 0;
    return 1;
}

int main()
{
    int k;
    cout << "cate nr prime doriti sa fie afisate? ";
    cin >> k;
    int n = 0, numar = 2;
    while (n < k) // cat timp nu s au generat toate cele k nr prime
    {
        if (ePrim(numar))
        {
            cout << numar << " ";
            n++;
        }
        numar++;
    }
    return 0;
}