#include <iostream>
#include <cstring>
#define maxd 10
#define maxs 100
#define maxb 120
#define neg(x) x == 1 ? 0 : 1
using namespace std;
int buf[10];
void output()
{
    const char *dict = "0123456789ABCDEF";
    int cnt = 0;
    for (int i = 0; i < 4; i++)
        cnt = buf[i] + cnt * 2;
    putchar(dict[cnt]);
}
int readint()
{
    int c;
    while (cin >> c)
        if (c != '\n')
            return c - '0';
}
int data[maxd][maxb][maxs];
int main()
{
    int T = 0;
    int d, s, b;
    while (cin >> d >> s >> b && d)
    {
        memset(data, 0, sizeof(data));
        memset(buf, 0, sizeof(buf));
        getchar();
        char p;
        cin >> p;
        getchar();
        for (int i = 0; i < d; i++)
            for (int j = 0; j < b; j++)
                for (int k = 0; k < s; k++)
                    data[i][j][k] = readint();
        bool verified;
        //校验
        for (int j = 0; j < b; j++)
        {
            verified = false;
            int r = -1, c = -1;
            int vp = j % d;
            for (int k = 0; k < s; k++)
            {
                int res = 0, xCnt = 0;
                for (int i = 0; i < d; i++)
                {
                    int temp = data[i][j][k];
                    if (temp == 72) //'x'
                    {
                        r = i, c = k;
                        xCnt++;
                        temp = 0;
                    }
                    res = res ^ temp;
                }
                if (vp == r) //校验位错误
                    break;
                if (xCnt == 0) //直接验证
                {
                    if (p == 'E' && res == 0) //偶校验
                        verified = true;
                    if (p == 'O' && res == 1) //奇校验
                        verified = true;
                }
                else if (xCnt == 1) //重建
                {
                    if (p == 'E')
                        data[r][j][c] = res;
                    if (p == 'O')
                        data[r][j][c] = neg(res);
                    verified = true;
                }
                else if (xCnt > 1) //错误
                    break;
            }
        }
        if (verified)
        {
            printf("Disk set %d is valid, contents are: ", ++T);
            //输出数据内容
            int cnt = 0;
            for (int j = 0; j < b; j++)
            {
                int vp = j % d;
                for (int i = 0; i < d; i++)
                    for (int k = 0; k < s; k++)
                        if (i != vp)
                        {
                            buf[cnt++] = data[i][j][k];
                            if (cnt == 4)
                            {
                                output();
                                cnt = 0;
                            }
                        }
            }
            for (int i = cnt; i < 4; i++)
            {
                buf[i] = 0;
            }
            if (cnt != 0)
                output();
        }
        else
        {
            printf("Disk set %d is invalid.", ++T);
        }
        printf("\n");
    }
}

//转自https://vjudge.net/problem/UVA-509