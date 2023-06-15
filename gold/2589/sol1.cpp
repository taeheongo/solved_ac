/*
    submission : https://www.acmicpc.net/source/62115556

    brute force + bfs

    time : O(N^2 * M^2)
    l의 개수 * bfs = N*M * bfs = 2500 * 2500 = 5000000
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
char a[50][50];
int visited[50][50];
vector<pair<int, int>> l_pos;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void bfs(int y, int x)
{
    queue<pair<int, int>> q;
    q.push({y, x});

    while (q.size())
    {
        auto top = q.front();
        q.pop();

        tie(y, x) = top;

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            if (a[ny][nx] != 'L' || visited[ny][nx] != -1)
                continue;

            visited[ny][nx] = visited[y][x] + 1;
            ret = max(ret, visited[ny][nx]);
            q.push({ny, nx});
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 'L')
                l_pos.push_back({i, j});
        }
    }

    for (auto e : l_pos)
    {
        memset(visited, -1, sizeof(visited));

        visited[e.first][e.second] = 0;
        bfs(e.first, e.second);
    }

    cout << ret << "\n";

    return 0;
}