#include <iostream>
using namespace std;

int produs(int n) // pb3
{
    int p = 1;
    while (n)
    {
        if (n % 10 != 0)
            p = p * (n % 10);
        n /= 10;
    }
    return p;
}

int numarNou(int n) // pb4
{
    int m = n;
    while (n)
    {
        m = m * 10 + n % 10;
        n /= 10;
    }
    return m;
}

int main()
{
    // 3. Sa se determine produsul cifrelor nevide ale lui n. Exemplu n=12045 => P=40
    cout << "a = ";
    int a;
    cin >> a;
    cout << "produsul cifrelor nevide a le lui " << a << " este " << produs(a) << endl;

    //     4. Fie n numar natural. Construiti un numar m din cifrele lui n si cifrele inversului sau, in
    // aceasta ordine. Ex: n=317 => inv=713 => m=317713
    cout << "b = ";
    int b;
    cin >> b;
    cout << "noul numar este " << numarNou(b) << endl;

    // 5. Fie n,m doua numere naturale. Verificati daca prin concatenarea lor se obtine un
    // palindrom.
    return 0;
}