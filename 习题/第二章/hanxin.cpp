#include <iostream>
using namespace std;
int main()
{
    int a, b, c, count = 0, i;
    while (cin >> a >> b >> c)
    {
        count++;
        for (i = 10; i < 101; ++i)
        {
            if (i % 3 == a && i % 5 == b && i % 7 == c)
            {
                cout << "Case " << count << ':' << i << endl;
                break;
            }
        }
        if (i == 101)
        {
            cout << "Case " << count << ": No answer" << endl;
        }
    }
}