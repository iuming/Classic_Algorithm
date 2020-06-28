#include <iostream>
#include <cstring>
#include <iomanip>
#define N 11
using namespace std;
int main()
{
    int r, c, num[N][N], flag = 0;
    char s[N][N];
    while (cin >> r >> c && r)
    {
        int i, j, k, t = 0, m, n;
        flag++;

        for (i = 0; i < r; i++)
            for (j = 0; j < c; j++)
                num[i][j] = 0;

        for (i = 0; i < r; i++)
            cin >> s[i];

        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
                if (((i - 1) < 0) || ((j - 1) < 0) || (s[i - 1][j] == '*') || (s[i][j - 1] == '*'))
                    if (s[i][j] != '*')
                        num[i][j] = ++t;
        }

        if (flag > 1)
            cout << endl;
        cout << "puzzle #" << flag << ',' << endl;
        cout << "Across" << endl;

        for (i = 0; i < r; i++)
        {

            for (j = 0; j < c; j++)
            {
                n = 0;
                if ((j == 0 || s[i][j - 1] == '*') && s[i][j] != '*')
                {
                    m = j;
                    cout << setprecision(3) << num[i][j] << '.';
                    n = 1;
                }

                if (n)
                {
                    for (k = m; k < c && s[i][k] != '*'; k++)
                        cout << s[i][k];
                    cout << endl;
                }
            }
        }
        cout << "Down" << endl;
        for (i = 0; i < r; i++)
        {
            for (j = 0; j < c; j++)
            {
                n = 0;

                if ((i == 0 || s[i - 1][j] == '*') && s[i][j] != '*')
                {
                    m = i;
                    cout << setprecision(3) << num[i][j] << '.';
                    n = 1;
                }

                if (n)
                {
                    for (k = m; k < r && s[k][j] != '*'; k++)
                        cout << s[k][j];
                    cout << endl;
                }
            }
        }
    }
    return 0;
}