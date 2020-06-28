#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
int main()
{
    int n, m, count = 0;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
        {
            return 0;
        }
        count++;
        double sum = 0;
        for (int i = n; i < m + 1; ++i)
        {
            sum += 1 / pow(i, 2);
        }
        cout << fixed << setprecision(5) << "Case " << count << ": " << sum << endl;
    }
}