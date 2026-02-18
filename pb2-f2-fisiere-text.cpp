/* DATE.IN contine cel puțin 2 si cel mult 1 milion de numere intregi de maxim 9 cifre fiecare.
Determinati cele mai mari 3 numere distincte din fisier. (variantă: aceeași cerință dar
numerele să nu fie neapărat distincte) */

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main()
{
    ifstream f("in/17-02-26-ddate.in");
    int a, max1, max2, max3; // max1 > max2 > max3
    max1 = INT_MIN + 2;
    max2 = INT_MIN + 1;
    max3 = INT_MIN;
    while (f >> a)
    {
        if (a != max1 && a != max2 && a != max3)
        {
            if (a > max1)
            {
                max3 = max2;
                max2 = max1;
                max1 = a;
            }
            else if (a > max2)
            {
                max3 = max2;
                max2 = a;
            }
            else if (a > max3)
                max3 = a;
        }
    }
    cout << max1 << " " << max2 << " " << max3 << endl;
    f.close();
    return 0;
}