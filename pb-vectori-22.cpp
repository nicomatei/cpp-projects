// inlocuiti nr negative cu patratele lor

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/09-02-26-vector22.in");
    int n;
    fin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    for (int i = 1; i <= n; i++)
        if (v[i] < 0)
            cout << v[i] * v[i] << " ";
        else
            cout << v[i] << " ";
    fin.close();
    return 0;
}