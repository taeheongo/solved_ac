/*
    submission : https://www.acmicpc.net/source/61812040

    connected component => dfs or bfs

    문제에서 좌표로 나온 값이 인덱스와 정확히 일치하지 않는다. 작은 박스 하나의 오른쪽 위 점의 좌표를 주기때문에 이를 조심해야 함.
*/

#include <bits/stdc++.h>

using namespace std;

int m, n, k;
const int N = 100;
int a[N][N];
bool visited[N][N];
int sy, sx, ey, ex;
vector<int> ret;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, int &cnt)
{
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
        if (a[ny][nx] || visited[ny][nx])
            continue;

        cnt++;
        dfs(ny, nx, cnt);
    }
}

int main()
{
    cin >> m >> n >> k;

    while (k--)
    {
        cin >> sx >> sy >> ex >> ey;
        for (int i = sy; i < ey; i++)
        {
            for (int j = sx; j < ex; j++)
            {
                a[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (a[i][j] || visited[i][j])
                continue;

            int cnt = 1;
            dfs(i, j, cnt);
            ret.push_back(cnt);
        }
    }

    sort(ret.begin(), ret.end());

    cout << ret.size() << "\n";
    for (int e : ret)
    {
        cout << e << " ";
    }

    return 0;
}