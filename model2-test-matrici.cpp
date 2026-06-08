// Scrieți un singur program C++ pentru cerințele de mai jos:

#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // 1) Să se citească din fișierul DATE.IN numărul natural n, (4<=n<=30), apoi elementele unei matrici pătratice
    // a cu n linii şi n coloane, cu elemente numere naturale distincte de maxim 2 cifre.Tipăriţi pe ecran matricea.
    ifstream fin("in/matrice-patratica.in");
    int n;
    fin >> n;
    int a[n + 1][n + 1];
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            fin >> a[i][j];
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            cout << a[i][j] << " ";
        cout << endl;
    }
    cout << endl;

    // 2) Un element este triangular dacă se poate scrie ca sumă de numere naturale consecutive începând de la 1.
    // Ex 6=1+2+3,  15=1+2+3+4+5 sunt nr. triangulare. Afișați elementele triangulare din matrice, mesaj dacă nu există.
    bool triangular = false;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int suma = 0;
            int k = 1;
            while (a[i][j] > suma && a[i][j] != 0)
            {
                suma += k;
                k++;
            }
            if (a[i][j] == suma)
            {
                cout << a[i][j] << " ";
                triangular = true;
            }
        }
    }
    if (!triangular)
        cout << "nu exista nr. triangulare";
    cout << endl;

    // 3) Verificați dacă în matrice alternează paritățile elementelor alăturate, conform parcurgerii pe coloane

    // 4) Afișați numerele de ordine ale liniilor “simetrice”. O linie este considerată “simetrică” dacă elementele luate în
    // ordine de la stânga la dreapta sunt la fel cu parcurgerea de la dreapta la stânga. Mesaj dacă nu există astfel de linii.

    // 5) Construiți matricea b cu aceleași dimensiuni ca matricea inițială, în care  b[i][j]=numărul de factori primi
    //  din descompunerea lui a[i][j]     Tipăriţi pe ecran matricea b.

    //  6) Eliminați linia și coloana pe care se află maximul, respectiv minimul din matrice

    return 0;
}