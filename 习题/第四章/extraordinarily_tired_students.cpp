#include <iostream>
using namespace std;
int main()
{
    int n, cases = 0;
    while (cin >> n && n)
    {
        int A[32], B[32], C[32], D[32];
        int sleep = 0, awake = 0, cycle = 1;
        for (int i = 0; i < n; i++)
        {
            cin >> A[i] >> B[i] >> C[i];
            D[i] = A[i] + B[i];
            cycle *= D[i];
        }
        int ret = -1;
        for (int time = 1; time <= cycle; time++)
        {
            awake = 0, sleep = 0;
            for (int i = 0; i < n; i++)
                if (C[i] <= A[i])
                    awake++;
                else
                    sleep++;
            if (awake == n)
            {
                ret = time;
                break;
            }
            for (int i = 0; i < n; i++)
            {
                C[i]++;
                if (C[i] == D[i] + 1)
                {
                    C[i] = 1;
                }
                else if (C[i] == A[i] + 1 && awake >= sleep)
                {
                    C[i] = 1;
                }
            }
        }
        cout << "Case " << ++cases << ", " << ret << endl;
    }
    return 0;
}