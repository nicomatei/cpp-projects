#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int n, v[101];
    ifstream fin("in/vectori111.in");
    fin >> n;
    for (int i = 1; i <= n; i++)
        fin >> v[i];
    // 3)
    cout << "perechile sunt: " << endl;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i != j)
            {
                int x = v[j], p = 1, y = v[i];
                if (y == 0)
                    p = 10;
                else
                    while (y > 0)
                    {
                        p *= 10;
                        y /= 10;
                    }
                bool found = false;
                while (x > 0 || (x == 0 && v[i] == 0))
                {
                    if (x % p == v[i])
                    {
                        found = true;
                        break;
                    }
                    x /= 10;
                    if (x == 0)
                        break;
                }
                if (found)
                    cout << v[i] << " si " << v[j] << endl;
            }
        }
    }
    return 0;
}