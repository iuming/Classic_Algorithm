#include <iostream>
#include <cstring>
using namespace std;
char pq[10][10];
char rev(char tmp)
{
    if (tmp == 'B')
        return 'W';
    else if (tmp == 'W')
        return 'B';
}
bool test(int x, int y, char player, int swft)
{
    if (pq[x][y] != '-')
        return false;
    int cnt = 0, pos = x - 1, posx, posy, flag = 0;
    char enemy = rev(player);
    while (pos > 1 && pq[pos][y] == enemy)
        ++cnt, --pos;
    if (pq[pos][y] == player && cnt)
    {
        if (swft)
            for (int i = x; i > pos; --i)
                pq[i][y] = player;
        flag = 1;
    }
    cnt = 0;
    pos = y - 1;
    while (pos > 1 && pq[x][pos] == enemy)
        ++cnt, --pos;
    if (pq[x][pos] == player && cnt)
    {
        if (swft)
            for (int i = y; i > pos; --i)
                pq[x][i] = player;
        flag = 1;
    }
    cnt = 0;
    pos = x + 1;
    while (pos < 8 && pq[pos][y] == enemy)
        ++cnt, ++pos;
    if (pq[pos][y] == player && cnt)
    {
        if (swft)
            for (int i = x; i < pos; ++i)
                pq[i][y] = player;
        flag = 1;
    }
    cnt = 0;
    pos = y + 1;
    while (pos < 8 && pq[x][pos] == enemy)
        ++cnt, ++pos;
    if (pq[x][pos] == player && cnt)
    {
        if (swft)
            for (int i = y; i < pos; ++i)
                pq[x][i] = player;
        flag = 1;
    }
    cnt = 0;
    posx = x - 1;
    posy = y - 1;
    while (posx > 1 && posy > 1 && pq[posx][posy] == enemy)
        ++cnt, --posx, --posy;
    if (pq[posx][posy] == player && cnt)
    {
        if (swft)
            for (int i = x, j = y; i > posx && j > posy; --i, --j)
                pq[i][j] = player;
        flag = 1;
    }
    cnt = 0;
    posx = x + 1;
    posy = y + 1;
    while (posx < 8 && posy < 8 && pq[posx][posy] == enemy)
        ++cnt, ++posx, ++posy;
    if (pq[posx][posy] == player && cnt)
    {
        if (swft)
            for (int i = x, j = y; i < posx && j < posy; ++i, ++j)
                pq[i][j] = player;
        flag = 1;
    }
    cnt = 0;
    posx = x + 1;
    posy = y - 1;
    while (posx < 8 && posy > 1 && pq[posx][posy] == enemy)
        ++cnt, ++posx, --posy;
    if (pq[posx][posy] == player && cnt)
    {
        if (swft)
            for (int i = x, j = y; i < posx && j > posy; ++i, --j)
                pq[i][j] = player;
        flag = 1;
    }
    cnt = 0;
    posx = x - 1;
    posy = y + 1;
    while (posx > 1 && posy < 8 && pq[posx][posy] == enemy)
        ++cnt, --posx, ++posy;
    if (pq[posx][posy] == player && cnt)
    {
        if (swft)
            for (int i = x, j = y; i > posx && j < posy; --i, ++j)
                pq[i][j] = player;
        flag = 1;
    }
    if (flag)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cin >> n;
    for (int rt = 0; rt < n; ++rt)
    {
        if (rt)
            cout << endl;
        for (int i = 1; i <= 8; ++i)
            for (int j = 1; j <= 8; ++j)
                cin >> pq[i][j];
        for (int i = 1; i <= 8; ++i)
            pq[i][9] = 0;
        char player;
        string op;
        cin >> player;
        while (cin >> op)
        {
            if (op[0] == 'Q')
            {
                for (int i = 1; i <= 8; ++i)
                    cout << pq[i] + 1 << endl;
                break;
            }
            else if (op[0] == 'L')
            {
                int cnt = 0;
                for (int i = 1; i <= 8; ++i)
                    for (int j = 1; j <= 8; ++j)
                        if (test(i, j, player, 0))
                        {
                            if (cnt++ == 0)
                                printf("(%d,%d)", i, j);
                            else
                                printf(" (%d,%d)", i, j);
                        }
                if (!cnt)
                    printf("No legal move.");
                cout << endl;
            }
            else if (op[0] == 'M')
            {
                int a = op[1] - '0', b = op[2] - '0';
                if (!test(a, b, player, 0))
                    player = rev(player); //如果当前不合法则换对方下
                test(a, b, player, 1);
                player = rev(player);
                int cntb = 0, cntw = 0;
                for (int i = 1; i <= 8; ++i)
                    for (int j = 1; j <= 8; ++j)
                        if (pq[i][j] == 'B')
                            ++cntb;
                        else if (pq[i][j] == 'W')
                            ++cntw;
                printf("Black -%3d White -%3d\n", cntb, cntw);
            }
        }
    }
    return 0;
}

//转自https://blog.csdn.net/weixin_42547447/article/details/84624769