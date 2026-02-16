// 12. Dintre cele n numere situate in fisierul NR.TXT, afisati-le pe cele care
// sunt echilibrate (au prima cifra egala cu ultima)

#include <iostream>
#include <fstream>
using namespace std;
int main()
{
    ifstream fin("in/16-02-26-nr.txt");
    int n, nr;
    fin >> n;
    for (int i = 1; i <= n; i++)
    {
        fin >> nr;
        int copNr = nr;
        while (copNr > 9)
        {
            copNr = copNr / 10;
        }
        if (nr % 10 == copNr % 10)
        {
            cout << nr << " ";
        }
    }
    fin.close();
    return 0;
}