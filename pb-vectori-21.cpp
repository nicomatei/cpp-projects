// afis pe ce pozitii sunt nr negative, mesaj daca nu sunt

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/09-02-26-vector21.in");
    int n, existaNeg = 0;
    fin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= n; i++)
        if (v[i] < 0)
        {
            cout << i << " ";
            existaNeg = 1;
        }
    if (existaNeg == 0)
        cout << "nu exista numere negative in sir";
    fin.close();
    return 0;
}