#include <iostream>
#include <algorithm>
using namespace std;

struct Pallets
{
    int x, y;
} a[6];

bool cmp(Pallets a, Pallets b)
{
    return a.x != b.x ? a.x < b.x : a.y > b.y;
}

bool isOk(Pallets a[6])
{
    if (a[0].x != a[1].x || a[2].x != a[3].x || a[4].x != a[5].x || a[0].y != a[1].y || a[2].y != a[3].y || a[4].y != a[5].y)
    {
        return false;
    }
    if (a[0].x != a[2].x || a[0].y != a[4].y || a[2].y != a[4].x)
    {
        return false;
    }
    return true;
}

int main()
{
    int x, y;
    while (cin >> x >> y)
    {
        a[0].x = x;
        a[0].y = y;
        if (a[0].x > a[0].y)
        {
            swap(a[0].x, a[0].y);
        }
        for (int i = 1; i < 6; i++)
        {
            cin >> x >> y;
            a[i].x = x;
            a[i].y = y;
            if (a[i].x > a[i].y)
                swap(a[i].x, a[i].y);
        }
        sort(a, a + 6, cmp);
        if (isOk(a))
            cout << "POSSIBLE" << endl;
        else
            cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}