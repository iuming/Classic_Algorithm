#include <iostream>
using namespace std;

bool H[10][10], V[10][10];
inline bool check(int r, int c, int size)
{
    for (int i = c; i < c + size; i++)
        if (!H[r][i] || !H[r + size][i])
            return false;
    for (int i = r; i < r + size; i++)
        if (!V[c][i] || !V[c + size][i])
            return false;
    return true;
}
int main()
{
    int n, Case = 1;
    while (cin >> n)
    {
        int i, j;
        for (i = 0; i <= n; i++)
            for (j = 0; j <= n; j++)
                V[i][j] = H[i][j] = false;
        int m, a, b;
        char c;
        cin >> m;
        while (m--)
        {
            getchar();
            cin >> c >> a >> b;
            if (c == 'H')
                H[a][b] = true;
            else
                V[a][b] = true;
        }
        int size[10] = {};
        for (i = 1; i <= n; i++) //size
        {
            for (j = 1; j + i <= n; j++)         //r
                for (int k = 1; k + i <= n; k++) //c
                    if (check(j, k, i))
                        size[i]++;
        }
        if (Case > 1)
            puts("\n**********************************\n");
        bool flag = true;
        cout << "Problem #" << Case++ << endl
             << endl;
        for (i = 1; i <= n; i++)
            if (size[i])
            {
                cout << size[i] << " square (s) of size " << i << endl;
                flag = false;
            }
        if (flag)
            puts("No completed squares can be found.");
    }

    return 0;
}