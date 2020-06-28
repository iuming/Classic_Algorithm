#include <iostream>
#include <set>
using namespace std;
int main()
{
    for (int i = 123; i < 333; ++i)
    {
        int j = i * 2;
        int k = i * 3;
        set<int> s;
        s.insert(i / 100);
        s.insert((i % 100) / 10);
        s.insert(i % 10);
        s.insert(j / 100);
        s.insert((j % 100) / 10);
        s.insert(j % 10);
        s.insert(k / 100);
        s.insert((k % 100) / 10);
        s.insert(k % 10);
        if (s.size() == 9)
            cout << i << ' ' << j << ' ' << k << endl;
    }
    return 0;
}