#include <iostream>
#include <fstream>
using namespace std;

// 9) cel mai mare nr din vector si de cate ori apare

int main()
{
    ifstream fin("in/vector-ex9-date.in");
    int max = 0, k = 0, n;
    fin >> n;
    int v[n + 1];
    for (int i = 1; i <= n; i++)
    {
        fin >> v[i];
        if (v[i] > max)
        {
            k = 1;
            max = v[i];
        }
        else
        {
            if (v[i] == max)
            {
                k++;
            }
        }
    }
    cout << max << " apare de " << k << " ori";
    fin.close();
    return 0;
}