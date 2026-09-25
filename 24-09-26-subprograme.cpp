#include <iostream>
using namespace std;

int nrCif(int n)
{
    int k = 0;
    do
    {
        k++;
        n /= 10;
    } while (n);
    return k;
}

int main()
{
    int a, b;
    cout << "dati val a: ";
    cin >> a;
    cout << "dati val b: ";
    cin >> b;
    cout << endl
         << "nr care se divid cu nr lor de cifre sunt: \n";
    for (int i = a; i <= b; i++)
        if (i % nrCif(i) == 0)
            cout << i << " ";
    return 0;
}