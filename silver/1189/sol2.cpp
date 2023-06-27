/*
    submission : https://www.acmicpc.net/source/62619265

    time : O(4^k) (1<= k <= r*c)
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 5;

int r, c, k;
char a[max_n + 4][max_n + 4];
int visited[max_n + 4][max_n + 4];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int go(int y, int x)
{
    if (y == 0 && x == c - 1)
    {
        if (visited[y][x] == k)
            return 1;
        return 0;
    }

    if (visited[y][x] == k)
        return 0;

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        if (a[ny][nx] == 'T' || visited[ny][nx])
            continue;

        visited[ny][nx] = visited[y][x] + 1;
        cnt += go(ny, nx);
        visited[ny][nx] = 0;
    }

    return cnt;
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

    visited[r - 1][0] = 1;

    cout << go(r - 1, 0) << "\n";

    return 0;
}