// Un copil face n aruncari cu zarul.
// a) de cate ori a aruncat fiecare numar?
// b) ce numar (numere) a aruncat cel mai des?

#include <iostream>

using namespace std;

int main()
{
    int n, fr[7] = {0}, x;
    cout << "cate aruncari au loc? ";
    cin >> n;
    cout << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << "dati valoarea dorita la aruncare: ";
        cin >> x;
        fr[x]++;
    }
    cout << endl;
    // a)
    for (int i = 1; i <= 6; i++)
    {
        cout << "valoarea " << i << " a fost aruncata de " << fr[i] << " ori" << endl;
    }
    cout << endl;
    // b)
    int max = 0;
    for (int i = 1; i <= 6; i++)
    {
        if (max < fr[i])
            max = fr[i];
    }
    cout << "valorile aruncate de cele mai multe ori sunt: ";
    for (int i = 1; i <= 6; i++)
    {
        if (max == fr[i])
            cout << i << " ";
    }

    return 0;
}