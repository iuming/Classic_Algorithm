#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[81];
    cin >> s;
    int sum = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == 'O')
            for (int j = i; j >= 0; --j)
            {
                if (s[j] == 'O')
                {
                    sum++;
                }
                else
                {
                    break;
                }
            }
    }
    cout << sum << endl;
}