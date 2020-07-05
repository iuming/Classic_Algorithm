#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>
#include <cctype>
#include <iostream>
int field[12][12];
int N, b_x, b_y;
using namespace std;
class Chess
{
public:
    char ch;
    int x;
    int y;
};
bool isInPalace(int x, int y)
{
    return 1 <= x && x <= 3 && 4 <= y && y <= 6;
}
bool isInBorder(int x, int y)
{
    if (1 <= x && x <= 10 && 1 <= y && y <= 9)
        return true;
    else
        return false;
}
bool catched_by(const Chess &chess, int bx, int by)
{
    //nx,ny 是对方棋子的postion
    /*  如果自己已经被吃掉，那就肯定不能吃掉对方    */
    if (chess.x == bx && chess.y == by)
    {
        return false;
    }
    //判断chess的种类

    //如果是车或者帅
    if (chess.ch == 'R' || chess.ch == 'G')
    {
        //方位控制
        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++)
        {
            int nx = chess.x;
            int ny = chess.y;
            //对该方位不断直线搜索
            while (true)
            {
                nx += dx[i];
                ny += dy[i];
                // 如果越界或者遇到红方棋子
                if (!isInBorder(nx, ny) || isupper(field[nx][ny]))
                    break;
                else if (field[nx][ny] == 'b') //吃掉对方
                    return true;
            }
        }
    }
    else if (chess.ch == 'H')
    {
        //马的8种可能方位
        int dx[8] = {2, 1, -2, -1, 2, 1, -2, -1};
        int dy[8] = {1, 2, 1, 2, -1, -2, -1, -2};
        //对每一种方位
        for (int i = 0; i < 8; i++)
        {
            int nx = chess.x;
            int ny = chess.y;
            //如果没有磐马角
            if (isInBorder(nx + (dx[i] / 2), ny + (dy[i] / 2)) && field[nx + (dx[i] / 2)][ny + (dy[i] / 2)] == 0)
            {
                nx += dx[i];
                ny += dy[i];
                //如果吃掉黑方的帅
                if (isInBorder(nx, ny) && field[nx][ny] == 'b')
                    return true;
            }
        }
    }
    else if (chess.ch == 'C')
    {
        //炮的四种打击方向
        int dx[4] = {1, -1, 0, 0};
        int dy[4] = {0, 0, 1, -1};
        //针对每一个方向
        for (int i = 0; i < 4; i++)
        {
            int nx = chess.x;
            int ny = chess.y;
            //找到第一个炮台
            enum found
            {
                isOut = 1,
                isBlack,
                isFriend
            };
            found paoTai = isOut;
            while (true)
            {
                nx += dx[i];
                ny += dy[i];
                //如果找到炮台,就跳出循环

                if (!isInBorder(nx, ny))
                {
                    paoTai = isOut;
                    break;
                }
                else
                {
                    if (field[nx][ny] == 'b')
                    {
                        paoTai = isBlack;
                        break;
                    }
                    else if (isupper(field[nx][ny]))
                    {
                        paoTai = isFriend;
                        break;
                    }
                }
            }
            //如果paotai== isFriend 表示找到炮台
            if (paoTai != isFriend)
                continue;
            //找黑方
            while (true)
            {
                nx += dx[i];
                ny += dy[i];
                if (!isInBorder(nx, ny))
                {
                    break;
                }
                else
                {
                    if (field[nx][ny] == 'b')
                    {
                        return true;
                    }
                    else if (isupper(field[nx][ny]))
                    {
                        break;
                    }
                }
            }
        }
    }

    return false;
}
bool catched_by(const vector<Chess> &Red, int nx, int ny)
{
    for (int i = 0; i < N; i++)
    {
        if (catched_by(Red[i], nx, ny))
        {
            return true;
        }
    }
    return false;
}

void print()
{
    for (int i = 1; i <= 10; i++)
    {
        for (int j = 1; j <= 9; j++)
        {
            if (field[i][j] != 0)
            {
                printf("%c", field[i][j]);
            }

            else
                printf("O");
        }
        cout << endl;
    }
    cout << endl;
}

bool black_win()
{
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};
    for (int i = 0; i < 4; i++)
    {
        int nx = b_x;
        int ny = b_y;
        //对该方位不断直线搜索
        while (true)
        {
            nx += dx[i];
            ny += dy[i];
            // 如果越界或者遇到红方棋子
            if (isInBorder(nx, ny))
            {
                if (field[nx][ny] == 'G')
                    return true;
                else if (field[nx][ny] != 0)
                    return false;
            }
            else
                break; //如果遇到出界就赶紧推出这个直线搜索循环
        }
    }
    return false;
}

int main()
{
    //b represent 黑方的帅
    while (cin >> N >> b_x >> b_y && N)
    {
        //初始化field数组
        memset(field, 0, sizeof(field));
        vector<Chess> Red(N);
        for (int i = 0; i < N; i++)
        {
            cin >> Red[i].ch >> Red[i].x >> Red[i].y;
            field[Red[i].x][Red[i].y] = Red[i].ch;
        }
        //draw plot
        field[b_x][b_y] = 'b';
        //test
        //print();
        if (black_win())
        {
            printf("NO\n");
            continue;
        }
        field[b_x][b_y] = 0;

        int dx[4] = {1, 0, -1, 0};
        int dy[4] = {0, 1, 0, -1};
        bool Black_Servive = false;
        for (int i = 0; i < 4; i++)
        {
            //更新画图
            int nx = b_x + dx[i];
            int ny = b_y + dy[i];
            int temp = field[nx][ny];
            field[nx][ny] = 'b';
            // print();
            //test

            if (!isInPalace(nx, ny)) //黑方帅不再皇宫中
            {
                //continue 之前要还原图
                field[nx][ny] = temp;
                continue;
            }
            else if (!catched_by(Red, nx, ny))
            {
                Black_Servive = true;
                break;
            }
            //还原画图
            field[nx][ny] = temp;
        }
        if (Black_Servive)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}

//转自https://blog.csdn.net/qq_40510397/article/details/80119198