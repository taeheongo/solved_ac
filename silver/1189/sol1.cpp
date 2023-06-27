/*
    submission : https://www.acmicpc.net/source/62618309

    time : O(4^k) (1 <= k <= r*c)
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5;

int r, c, k, ret;
char a[max_n + 4][max_n + 4];
bool visited[max_n + 4][max_n + 4];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void go(int y, int x, int cnt)
{
    if (y == 0 && x == c - 1)
    {
        if (cnt == k)
            ret++;
        return;
    }

    if (cnt == k)
        return;

    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        if (a[ny][nx] == 'T' || visited[ny][nx])
            continue;

        go(ny, nx, cnt + 1);
    }

    visited[y][x] = 0;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> k;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    go(r - 1, 0, 1);

    cout << ret << "\n";

    return 0;
}