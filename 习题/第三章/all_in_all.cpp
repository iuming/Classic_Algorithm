#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string s, t;
    while (cin >> s >> t)
    {
        int n = 0;
        for (int i = 0; i < t.length() && n < s.length(); i++)
            if (t[i] == s[n])
                n++;
        cout << ((n == s.length()) ? "Yes" : "No") << endl;
    }
    return 0;
}