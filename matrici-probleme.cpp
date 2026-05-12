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
    cout << endl;
    // 3. det sumele fiecarei linii si memorati le in coloana 0
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            m[i][0] += m[i][j];
    for (int i = 1; i <= a; i++)
        cout << "suma liniei " << i << " este " << m[i][0] << endl;
    cout << endl;
    // 4. afis nr de ordine ale liniilor cu suma max
    int max = 0;
    cout << "nr de ordine ale liniilor cu suma max: ";
    for (int i = 1; i <= a; i++)
    {
        if (m[i][0] > max)
        {
            max = m[i][0];
        }
    }
    for (int i = 1; i <= a; i++)
    {
        if (max == m[i][0])
        {
            cout << i << " ";
        }
    }
    cout << endl;
    cout << endl;
    // 5. det max fiecarei coloane si memorati in linia 0
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
            m[0][j] += m[i][j];
    for (int j = 1; j <= b; j++)
        cout << "suma coloanei " << j << " este " << m[0][j] << endl;
    cout << endl;
    // 6. afis nr prime din matrice, mesaj daca nu exista
    for (int i = 1; i <= a; i++)
        for (int j = 1; j <= b; j++)
        {
            bool prim = true;
            if (m[i][j] < 2)
                prim = false;
            else
            {
                for (int d = 2; d * d <= m[i][j]; d++)
                    if (m[i][j] % d == 0)
                        prim = false;
            }
            if (prim)
            {
                cout << "la linia " << i << " coloana " << j << " se afla un nr prim: " << m[i][j] << endl;
            }
        }
    cout << endl;
    // 7. afis nr pare de pe liniile impare
    bool par = false;
    cout << "nr pare de pe liniile impare: ";
    for (int i = 1; i <= a; i += 2) // pt ca prima linie impara ii de fapt a 2-a pt ca pe prima ii nr de linii si coloane
        for (int j = 1; j <= b; j++)
            if (m[i][j] % 2 == 0)
            {
                cout << m[i][j] << " ";
                par = true;
            }
    if (!par)
        cout << "nu exista";
    cout << endl;
    cout << endl;
    // 8. det nr de ordine ale liniilor simetrice
    cout << "nr de ordin al liniilor simetrice: ";
    bool sim = false;
    for (int i = 1; i <= a; i++)
    {
        bool simetrice = true;
        for (int j = 1; j <= b / 2 && simetrice; j++)
        {
            if (m[i][j] != m[i][b - j + 1])
                simetrice = false;
        }
        if (simetrice)
        {
            cout << i << " ";
            sim = true;
        }
    }
    if (!sim)
        cout << "nu exista";
    cout << endl;
    cout << endl;
    // 9. verif daca matricea are elem in ordine strict crescatoare conform parcurgerii ⬇️ ➡️
    bool strictcrescator = true;
    int precedent = -1;
    for (int j = 1; j <= b && strictcrescator; j++)
        for (int i = 1; i <= a && strictcrescator; i++)
        {
            if (m[i][j] <= precedent)
                strictcrescator = false;
            precedent = m[i][j];
        }
    if (strictcrescator)
        cout << "elementele sunt strict crescatoare";
    else
        cout << "elementele nu sunt strict crescatoare";
    cout << endl;
    cout << endl;
    // 10. se citeste x, afis nr de ordine a coloanei care il contin pe x de cele mai multe ori
    int x;
    cout << "x = ";
    cin >> x;
    int maxx = 0;
    for (int j = 1; j <= b; j++)
    {
        int xtemp = 0;
        for (int i = 1; i <= a; i++)
            if (m[i][j] == x)
                xtemp++;
        if (xtemp > maxx)
            maxx = xtemp;
    }
    if (maxx == 0)
        cout << x << " nu apare in matrice";
    else
        cout << "coloana in care " << x << " apare de cele mai multe ori este: ";
    for (int j = 1; j <= b; j++)
    {
        int xtemp = 0;
        for (int i = 1; i <= a; i++)
            if (m[i][j] == x)
                xtemp++;
        if (xtemp == maxx)
            cout << j << " ";
    }
    return 0;
}