// Doi copii arunca zarul de mai multe ori fiecare. Primul copil arunca pana obtine 6.
// Al doilea copil arunca pana obtine 1. Aruncarile lor se memoreaza in doi vectori.
// a) de cate ori a aruncat fiecare?
// b) care a aruncat o suma totala a fetelor mai mare?
// c) ce zar a aruncat fiecare cel mai des?

#include <iostream>
using namespace std;

int main()
{
    int z1[101], z2[101], n1 = 0, n2 = 0, zar;
    cout << "incepe primul copil: ";
    do
    {
        cin >> zar;
        n1++;
        z1[n1] = zar;
    } while (zar != 6);
    cout << "incepe al doilea copil: ";
    do
    {
        cin >> zar;
        n2++;
        z2[n2] = zar;
    } while (zar != 1);
    cout << endl;
    // a)
    cout << "primul copil a aruncat zarul de " << n1 << " ori" << endl;
    cout << "al doilea copil a aruncat zarul de " << n2 << " ori" << endl;
    // b)
    int s1, s2;
    for (int i = 1; i <= n1; i++)
        s1 += z1[i];
    for (int i = 1; i <= n2; i++)
        s2 += z2[i];
    if (s1 == s2)
        cout << "amandoi au aruncat aceasi suma: " << s1 << endl;
    else
    {
        if (s1 > s2)
            cout << "primul copil: " << s1 << endl;
        else
            cout << "al doilea: " << s2 << endl;
    }
    // c)
    int fr1[7] = {0};
    for (int i = 1; i <= n1; i++)
        fr1[z1[i]]++;
    for (int i = 1; i <= n2; i++)
        fr1[z2[i]]++;
    return 0;
}