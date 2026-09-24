#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    // ex 3 - inserarea elem b1, ... bm in sirul a de n elem incepand cu poz k
    int a[201], b[101], m, n, i, j, k;
    ifstream fin("17-09-26-model3.in/in");

    for (i = n; i >= k; i--)
        a[i + m] = a[i];
    n = n + m;
    return 0;
}