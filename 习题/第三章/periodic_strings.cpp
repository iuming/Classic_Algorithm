#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    string a;
    cin >> a;
    for (int i = 1; i <= a.size(); ++i)
    {
        if (a.size() % i == 0)
        {
            int k = 1;
            for (int j = i; j < a.size(); ++j)
            {
                if (a[j] != a[j % i])
                {
                    k = 0;
                    break;
                }
            }
            if (k)
            {
                cout << i << endl;
                break;
            }
        }
    }
}