// 7. n elevi sunt înșirați pe un rând la ora de sport. Pentru fiecare elev se cunoaște înălțimea (în centimetri)
// a) Verificați dacă sunt cel puțin 2 elevi cu aceeași înălțime care să stea unul lângă celălalt. (mesaj DA/NU)
// b) Verificați dacă există un elev cu înălțimea maximă care să stea lângă unul de înălțime minimă (mesaj DA/NU)
// c) Ordonați elevii descrescător după înălțime. Verificați câți elevi au rămas în același loc după ordonare. (nu și-au schimbat locul în șir)
// d) Afișați fiecare înălțime și numărul de elevi cu acea înălțime
// e) Elevii cu înălțimea maximă și cei cu înălțimea minimă pleacă. Afișați înălțimile elevilor rămași.

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