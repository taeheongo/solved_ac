/*
    submission : https://www.acmicpc.net/source/61795033

    connected component 개수 => dfs, bfs
    노트에 아무 지역도 물에 잠기지 않을 수 있다. 높이의 최소값보다 더 낮은 높이로 비가 올 수 있다는 뜻. 비가 안올 수도 있음.
    즉, connected component의 개수는 최소 1이다.
    그래서 ret = 1로 초기화.
*/

#include <bits/stdc++.h>

using namespace std;

const int N = 100;
int n;
int a[N][N], visited[N][N];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, int h)
{
    visited[y][x] = 1;
    for (int i = 0; i < 4; i++)
    {
        const int ny = y + dy[i];
        const int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (a[ny][nx] <= h || visited[ny][nx])
            continue;

        dfs(ny, nx, h);
    }
}

int main()
{
    cin >> n;
    int max_h = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            max_h = max(max_h, a[i][j]);
        }
    }

    int ret = 1, cnt = 0;
    int h = max_h;
    while (h--)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (a[i][j] <= h || visited[i][j])
                    continue;

                dfs(i, j, h);
                cnt++;
            }
        }

        ret = max(ret, cnt);
        memset(visited, 0, sizeof(visited));
        cnt = 0;
    }

    cout << ret << "\n";

    return 0;
}