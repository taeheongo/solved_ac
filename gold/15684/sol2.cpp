/*
    submission : https://www.acmicpc.net/source/62593699

    back tracking

    total = (300 comb 0 + 300 comb 1 + 300 comb 1 + 300 comb 2 + 300 comb 3)

    time = O(total * n * h)
*/

#include <bits/stdc++.h>

using namespace std;

const int MAX_CNT = 32;

int n, m, h, a, b, ret = MAX_CNT;
bool visited[34][14];

bool check()
{
    for (int i = 1; i <= n; i++)
    {
        int start = i;
        for (int j = 1; j <= h; j++)
        {
            if (visited[j][start])
                start++;
            else if (visited[j][start - 1])
                start--;
        }

        if (start != i)
            return false;
    }

    return true;
}

void go(int y, int cnt)
{
    if (check())
    {
        ret = min(ret, cnt);
        return;
    }

    for (int i = y; i <= h; i++)
    {
        for (int j = 1; j <= n - 1; j++)
        {
            if (visited[i][j - 1] || visited[i][j] || visited[i][j + 1])
                continue;

            visited[i][j] = 1;
            go(i, cnt + 1);
            visited[i][j] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> h;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;
        visited[a][b] = 1;
    }

    go(1, 0);

    if (ret == MAX_CNT)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}
