// permutati circular cu o pozitie spre stanga sirul

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/09-02-26-vector18.in");
    int n;
    fin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    fin.close();
    int temp = v[1];
    for (int i = 1; i <= n - 1; i++)
        v[i] = v[i + 1];
    v[n] = temp;
    for (int i = 1; i <= n; i++)
        cout << v[i] << " ";
    return 0;
}