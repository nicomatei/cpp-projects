// det max la prima jumate si min la a doua jumate

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ifstream fin("in/09-02-26-vector15.in");
    int n;
    fin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    int max = v[1], min = v[n / 2 + 1];
    for (int i = 2; i <= n; i++)
        if (v[i] > max)
            max = v[i];
    for (int i = n / 2 + 2; i <= n; i++)
        if (v[i] < min)
            min = v[i];
    cout << "maximul primei jumatati este " << max << endl
         << "iar minimul celei de-a doua jumatati este " << min;
    fin.close();
    return 0;
}