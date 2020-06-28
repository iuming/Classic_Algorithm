#include <iostream>
#include <cstring>
#define MAXLEN 105
using namespace std;

int getMaxLength(char master[], int lenM, char driven[], int lenD)
{
    int i = 0, j = 0, matchPos = 0;
    while (i < lenM && j < lenD && matchPos < lenM)
    {
        if (master[i] - '0' + driven[j] - '0' <= 3)
        {
            ++i;
            ++j;
        }
        else
        {
            ++matchPos;
            i = matchPos;
            j = 0;
        }
    }
    if (lenM - matchPos >= lenD)
        return lenM;
    return lenD + matchPos;
}

int main()
{
    char master[MAXLEN], driven[MAXLEN];
    while (cin >> master >> driven)
    {
        int lenM = strlen(master);
        int lenD = strlen(driven);
        int x = getMaxLength(master, lenM, driven, lenD);
        int y = getMaxLength(driven, lenD, master, lenM);
        int num = x < y ? x : y;
        cout << num << endl;
    }
    return 0;
}