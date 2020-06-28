#include <iostream>
#include <cmath>
#include <cstring>
#define LL long long
using namespace std;
const double eps = 1e-7;
int main()
{
    char s[30];
    while (cin >> s && strcmp(s, "0e0") != 0)
    {
        LL A = s[0] - '0', B = 0;
        for (int i = 2; i < 17; i++)
            A = A * 10 + s[i] - '0';
        for (int i = 18; i < strlen(s); i++)
            B = B * 10 + s[i] - '0';
        double t = log10(A) + B - 15;
        bool flag = false;
        for (int i = 0; i < 10; i++)
        {
            for (int j = 1; j <= 30; j++)
            {
                double X = 1 - pow(2, -1 - i), Y = pow(2, j) - 1;
                double ans = log10(X) + Y * log10(2);
                if (fabs(ans - t) < eps)
                {
                    flag = true;
                    cout << i << ' ' << j << endl;
                    break;
                }
            }
            if (flag)
                break;
        }
    }
    return 0;
}