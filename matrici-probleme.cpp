#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    int a, b, m[101][101];
    ifstream fin("in/matrici-nr-nat.in");
    // 1. verif daca toate elem sunt != 0
    // citim matricea
    fin >> a >> b;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            fin >> m[i][j];
    // verif daca sunt dif de 0
    bool nenule = true;
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            if (m[i][j] == 0)
                nenule = false;
    if (nenule)
        cout << "numerele sunt nenule";
    else
        cout << "exista numere nule";
    cout << endl;
    // 2. verif daca toate nr sunt binare (doar din 0 si 1)
    bool binar = true;
    for (int i = 1; i <= a && binar; i++)
        for (int j = 1; j <= b && binar; j++)
        {
            int cop = m[i][j];
            if (cop != 0)
            {
                while (cop > 0)
                {
                    if (cop % 10 != 0 && cop % 10 != 1)
                        binar = false;
                    cop = cop / 10;
                }
            }
        }
    if (binar)
        cout << "e binar";
    else
        cout << "nu e binar";
    cout << endl;
    // 3. det sumele fiecarei linii si memorati le in coloana 0
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            m[i][0] += m[i][j];
    for (int i = 1; i <= a; i++)
        cout << "suma liniei " << i << " este " << m[i][0] << endl;
    cout << endl;

    return 0;
}