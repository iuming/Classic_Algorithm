#include <iostream>
#include <cstring>
#define ll long long
using namespace std;

int n, m;
int r[3003], u[3003], s[3003];

int main()
{
    while (cin >> n >> m)
    {
        int t = n;
        memset(r, 0, sizeof(r));
        memset(u, 0, sizeof(u));
        int count = 0;
        r[count++] = n / m;
        n = n % m;
        while (!u[n] && n)
        {
            u[n] = count;
            s[count] = n;
            r[count++] = 10 * n / m;
            n = 10 * n % m;
        }
        cout << t << '/' << m << '=' << r[0] << '.';
        for (int i = 1; i < count && i <= 50; i++)
        {
            if (n && s[i] == n)
                cout << '(';
            cout << r[i];
        }
        if (!n)
            cout << "(0";
        if (count > 50)
            cout << "...";
        cout << ")";
        int num = !n ? 1 : count - u[n];
        cout << "   " << num << " = number of digits in repeating cycle" << endl
                                                                           << endl;
    }
    return 0;
}