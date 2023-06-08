/*
    submission : https://www.acmicpc.net/source/61869528

    구현 방식만 쪼금 다름.
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

        for (int j = 0; j < w; j++)
        {
            a[i][j] = s[j] == '.' ? -1 : 0;
        }
    }

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
        {
            if (a[i][j] == 0)
            {
                int cnt = 1;
                while (j + 1 < w && a[i][j + 1] == -1)
                {
                    a[i][j + 1] = cnt++;
                    j++;
                }
            }
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