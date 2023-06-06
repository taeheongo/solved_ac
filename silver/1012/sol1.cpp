/*
    submission : https://www.acmicpc.net/source/61794807

    conneted component 개수 찾는 문제 => dfs or bfs
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 50;
bool a[N][N], visited[N][N];
int t, n, m, k;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;
        if (a[ny][nx] == 0 || visited[ny][nx])
            continue;

        dfs(ny, nx);
    }
}

int main()
{
    cin >> t;

    while (t--)
    {
        cin >> m >> n >> k;

        int y, x;
        while (k--)
        {
            cin >> x >> y;
            a[y][x] = 1;
        }

        int ret = 0;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (a[i][j] == 0 || visited[i][j])
                    continue;
                dfs(i, j);
                ret++;
            }
        }
        cout << ret << "\n";
        memset(visited, 0, sizeof(visited));
        memset(a, 0, sizeof(a));
    }

    return 0;
}