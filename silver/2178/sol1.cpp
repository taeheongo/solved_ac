/*
    submission : https://www.acmicpc.net/source/61792555

    가중치가 같은 맵(그래프)에서 최단거리 구하는 문제 => bfs
    입력받을 때 조심.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, y, x;
const int N = 104;
int a[N][N], visited[N][N];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = 1;

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (a[ny][nx] == 0 || visited[ny][nx])
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            q.push({ny, nx});
        }
    }

    cout << visited[n - 1][m - 1] << "\n";

    return 0;
}