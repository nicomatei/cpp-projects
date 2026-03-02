#include <iostream>
using namespace std;

int main()
{
    int n, a[100];
    cout << "cate nr va contine sirul? ";
    cin >> n;
    cout << "dati nr ";
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    // 8) media aritmetica a nr pare
    int catePare = 0, suma = 0;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 0)
        {
            catePare++;
            suma += a[i];
        }
    }
    if (catePare == 0)
    {
        cout << "nu exista nr pare in vector\n";
    }
    else
    {
        cout << "media arit a celor pare este: " << (float)suma / catePare << endl;
    }
    return 0;
}