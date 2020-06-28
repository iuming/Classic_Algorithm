#include <iostream>
#include <cstring>
#define IOS ios::sync_with_stdio(false)
using namespace std;
string s[51];
int main()
{
    IOS;
    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            cin >> s[i];
        string res;
        int ans = 0;
        for (int i = 0; i < m; i++)
        {
            int A = 0, C = 0, G = 0, T = 0;
            for (int j = 1; j <= n; j++)
            {
                if (s[j][i] == 'A')
                    A++;
                if (s[j][i] == 'C')
                    C++;
                if (s[j][i] == 'G')
                    G++;
                if (s[j][i] == 'T')
                    T++;
            }
            if (A >= C && A >= G && A >= T)
            {
                res += 'A';
                ans += (n - A);
                continue;
            }
            if (C >= A && C >= G && C >= T)
            {
                res += 'C';
                ans += (n - C);
                continue;
            }
            if (G >= C && G >= A && G >= T)
            {
                res += 'G';
                ans += (n - G);
                continue;
            }
            if (T >= C && T >= G && T >= A)
            {
                res += 'T';
                ans += (n - T);
                continue;
            }
        }
        cout << res << endl;
        cout << ans << endl;
    }
    return 0;
}