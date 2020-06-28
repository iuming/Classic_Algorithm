#include <iostream>
#include <cstring>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int a[10];
    memset(a,0,sizeof(a));
    for (int i = 1; i <= n; ++i)
    {
        int s = i;
        do
        {
            a[s % 10]++;
            s /= 10;
        } while (s != 0);
    }
    for (int i = 0; i < 10; ++i)
    {
        cout << a[i] << endl;
    }
    return 0;
}