#include <iostream>
#include <iomanip>
using namespace std;
int main()
{
    int a, b, c, count = 0;
    while (cin >> a >> b >> c)
    {
        count++;
        if (a == 0 && b == 0 && c == 0)
            return 0;
        cout << fixed << setprecision(c) << "Case " << count << ": " << (double)a / b << endl;
    }
}