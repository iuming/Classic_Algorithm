#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    for (int i = 100; i < 1000; ++i)
    {
        int a, b, c;
        a = i / 100;
        b = (i % 100) / 10;
        c = i % 10;
        if (pow(a, 3) + pow(b, 3) + pow(c, 3) == i)
            cout << i << endl;
    }
    return 0;
}