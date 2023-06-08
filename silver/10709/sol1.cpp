/*
    submission : https://www.acmicpc.net/source/61868260

    구현
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int h, w, a[N][N];

int main()
{
    cin >> h >> w;

    string s("", w);
    for (int i = 0; i < h; i++)
    {
        cin >> s;
        int cnt = -1;
        for (int j = 0; j < w; j++)
        {
            if (s[j] == 'c')
            {
                cnt = 0;
            }

            a[i][j] = cnt == -1 ? cnt : cnt++;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}