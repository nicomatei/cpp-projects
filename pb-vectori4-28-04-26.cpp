// se cit n nr nat si un vector cu 2*n elemente nat
// constr n fractii folosind elem vectorului incat suma fractiilor sa fie max si fiecare elem sa apara o data
#include <iostream>
using namespace std;

int main()
{
    int n, v[201], temp;
    cout << "n = ";
    cin >> n;
    for (int i = 1; i <= 2 * n; i++)
    {
        cin >> v[i];
    }
    for (int i = 1; i <= 2 * n; i++)
    {
        for (int j = i + 1; j <= 2 * n; j++)
        {
            if (v[i] > v[j])
            {
                temp = v[i];
                v[i] = v[j];
                v[j] = temp;
            }
        }
    }
    cout << "fractiile sunt: " << endl;
    for (int i = 1; i <= n; i++)
    {
        cout << v[2 * n - i + 1] << "/" << v[i] << " ";
    }
    return 0;
}