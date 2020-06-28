#include <iostream>
#include <cstring>
#define N 5
using namespace std;
int main()
{
    char a[N][N];
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            cin >> a[i][j];
    int c, d;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            if (a[i][j] == '0')
            {
                c = i;
                d = j;
            }
    string s;
    cin >> s;
    cout << s.size() << endl;
    for (int i = 0; i < s.size(); ++i)
    {
        if (s[i] != 0)
        {
            if (s[i] == 'R')
            {
                a[c][d] = a[c][d + 1];
                a[c][d + 1] = '0';
                d = d + 1;
            }
            if (s[i] == 'L')
            {
                a[c][d] = a[c][d - 1];
                a[c][d - 1] = '0';
                d = d - 1;
            }
            if (s[i] == 'B')
            {
                a[c][d] = a[c + 1][d];
                a[c + 1][d] = '0';
                c = c + 1;
            }
            if (s[i] == 'A')
            {
                a[c][d] = a[c - 1][d];
                a[c - 1][d] = '0';
                c = c - 1;
            }
        }
        else
        {
            break;
        }
    }
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
            cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}