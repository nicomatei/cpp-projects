// sa se scrie fct utile apoi sa se rezolve urmatoarele cerinte

#include <iostream>
using namespace std;

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

// a - sa se det nr de nr din intervalul [a, b) au suma cif mai mica sau exala cu cif max
int cifMax(int n)
{
    int maxim = 0;
    while (n)
    {
        int c = n % 10;
        if (c > maxim)
            maxim = c;
        n /= 10;
    }
    return maxim;
}

// b - de cate ori apare cif k data in nr din intervalul [a, b] dat
int nrAp(int n, int k)
{
    int cnt = 0;
    while (n > 0)
    {
        if (n % 10 == k)
            cnt++;
        n /= 10;
    }
    return cnt;
}

// d - det cel mai mare nr din interval ce are cif de control min
int cifControl(int n)
{
    while (n > 9)
        n = SumaCifre(n);
    return n;
}

int main()
{
    // calc cate nr din intervalul [a, b)
    // au cifra de control mai mica decat cif max din scrierea lor
    int a, b;
    cin >> a >> b;
    int cate = 0;
    for (int i = a; i < b; i++)
    {
        if (cifControl(i) < cifMax(i))
        {
            cout << i << " ";
            cate++;
        }
    }
    return 0;
}