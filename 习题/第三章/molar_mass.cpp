#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    char s[11];
    cin >> s;
    float sum = 0;
    for (int i = 0; i < strlen(s); ++i)
    {
        if (s[i] == 'C')
        {
            if (s[i + 1] > '0' && s[i + 1] <= '9')
            {
                sum += 12.01 * (int)(s[i + 1] - '0');
            }
            else
            {
                sum += 12.01;
            }
        }
        if (s[i] == 'H')
        {
            if (s[i + 1] > '0' && s[i + 1] <= '9')
            {
                sum += 1.008 * (int)(s[i + 1] - '0');
            }
            else
            {
                sum += 1.008;
            }
        }
        if (s[i] == 'O')
        {
            if (s[i + 1] > '0' && s[i + 1] <= '9')
            {
                sum += 16.00 * (int)(s[i + 1] - '0');
            }
            else
            {
                sum += 16.00;
            }
        }
        if (s[i] == 'N')
        {
            if (s[i + 1] > '0' && s[i + 1] <= '9')
            {
                sum += 14.01 * (int)(s[i + 1] - '0');
            }
            else
            {
                sum += 14.01;
            }
        }
    }
    cout << sum << endl;
    return 0;
}