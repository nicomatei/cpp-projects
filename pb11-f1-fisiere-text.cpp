// 11. Care sunt numerele de 3 cifre cu produsul cifrelor egal cu o valoare P
// data. Citirea lui P de la tastatura, afisarea in PRODUS.TXT.

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream f("out/produs-3-cifre.txt");
    cout << "ba... introdu aici un numar, ai inteles? o sa fac ce vreau eu oricum: ";
    int p, count = 0;
    cin >> p;
    cout << endl;
    for (int n = 100; n <= 999; n++)
    {
        if ((n % 10) * (n / 10 % 10) * (n / 100) == p)
        {
            cout << n << " ";
            f << n << " ";
            count++;
        }
    }
    cout << endl;
    if (count == 0)
        cout << "nu exista nr de care vreau eu!!!" << endl;
    else
        cout << "am gasit " << count << " nr de care am vrut eu" << endl;
    cout << endl;
    cout << "gata am facut ce am vrut, pa...!";
    cout << endl;
    f.close();
    return 0;
}
