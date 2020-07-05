#include <iostream>
#include <cstring>
#define maxn 100
using namespace std;
int l, chance;
char s[maxn], s2[maxn];
int win, lose;

void guess(char ch)
{
    int bad = 1;
    for (int i = 0; i < strlen(s); ++i)
        if (s[i] == ch)
        {
            l--;
            s[i] = ' ';
            bad = 0;
        }
    if (bad)
        --chance;
    if (!chance)
        lose = 1;
    if (!l)
        win = 1;
}

int main()
{
    int rnd;
    while (cin >> rnd >> s >> s2 && rnd != -1)
    {
        cout << "Round " << rnd << endl;
        win = lose = 0;
        l = strlen(s);
        chance = 7;
        for (int i = 0; i < strlen(s2); ++i)
        {
            guess(s2[i]);
            if (win || lose)
                break;
        }
        if (win)
            cout << "You win." << endl;
        else if (lose)
            cout << "You lose." << endl;
        else
            cout << "You chickened." << endl;
    }
    return 0;
}