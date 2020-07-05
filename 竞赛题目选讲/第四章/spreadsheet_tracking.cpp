#include <iostream>
#include <cstring>
#define maxd 10000
using namespace std;

struct Command
{
    char c[5];
    int r1, r2, c1, c2;
    int a, x[20];
} cmd[maxd];
int r, c, n;

int simulate(int *r0, int *c0)
{
    for (int i = 0; i < n; ++i)
    {
        if (cmd[i].r1 == *r0 && cmd[i].c1 == *c0)
        {
            *r0 = cmd[i].r2;
            *c0 = cmd[i].c2;
        }
        else if (cmd[i].r2 == *r0 && cmd[i].c2 == *c0)
        {
            *r0 = cmd[i].r1;
            *c0 = cmd[i].c1;
        }
        else
        {
            int dr = 0, dc = 0;
            for (int j = 0; j < cmd[i].a; ++j)
            {
                int x = cmd[i].x[j];
                if (cmd[i].c[0] == 'I')
                {
                    if (cmd[i].c[0] == 'R' && x <= *r0)
                        dr++;
                    if (cmd[i].c[0] == 'C' && x <= *c0)
                        dc++;
                }
                else
                {
                    if (cmd[i].c[1] == 'R' && x == *r0)
                        return 0;
                    if (cmd[i].c[1] == 'C' && x == *c0)
                        return 0;
                    if (cmd[i].c[1] == 'R' && x < *r0)
                        dr--;
                    if (cmd[i].c[1] == 'C' && x < *c0)
                        dc--;
                }
            }
            *r0 += dr;
            *c0 += dc;
        }
    }
    return 1;
}

int main()
{
    int r0, c0, q, kase = 0;
    while (cin >> r >> c >> n && r)
    {
        for (int i = 0; i < n; i++)
        {
            cin >> cmd[i].c;
            if (cmd[i].c[0] == 'E')
            {
                cin >> cmd[i].r1 >> cmd[i].c1 >> cmd[i].r2 >> cmd[i].c2;
            }
            else
            {
                cin >> cmd[i].a;
                for (int j = 0; j < cmd[i].a; ++j)
                    cin >> cmd[i].x[j];
            }
        }
        if (kase > 0)
            cout << endl;
        cout << "Spreadsheet #" << ++kase << endl;
        cin >> q;
        while (q--)
        {
            cin >> r0 >> c0;
            cout << "Cell data in (" << r0 << ',' << c0 << ')';
            if (!simulate(&r0, &c0))
                cout << "GONE" << endl;
            else
                cout << "moved to (" << r0 << ',' << c0 << ')' << endl;
        }
    }
    return 0;
}