#include <iostream>
using namespace std;
int main()
{
    int n, i = 0, cate = 0;
    cout << "introduceti un numar: ";
    cin >> n;
    int copn = n;
    while (i < 10)
    {
        while (n > 0)
        {
            if (n % 10 == i)
                cate++;
            n = n / 10;
        }
        if (cate > 0)
            cout << "Cifra " << i << " apare de " << cate << " ori." << endl;
        i++;
        n = copn;
        cate = 0;
    }
    return 0;
}