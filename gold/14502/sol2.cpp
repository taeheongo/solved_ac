/*
    submission : https://www.acmicpc.net/source/61937066

    더 깔끔한 코드. 로직은 같음.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int a[8][8];
bool visited[8][8];
vector<pair<int, int>> v0; // 값이 0인 좌표의 모음
vector<pair<int, int>> v2; // 값이 2인 좌표의 모음

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, int &val)
{
    visited[y][x] = 1;
    val++;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[ny][nx] || a[ny][nx] == 1)
            continue;

        dfs(ny, nx, val);
    }
}

int go()
{
    int y, x, val = 0;
    for (auto e : v2)
    {
        tie(y, x) = e;
        if (visited[y][x] == 0)
        {
            dfs(y, x, val);
        }
    }

    int num_1 = n * m - (int)v2.size() - (int)v0.size() + 3; // 벽의 개수
    val = n * m - val - num_1;                               // 안전한 영역

    return val;
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
            if (a[i][j] == 0)
            {
                v0.push_back({i, j});
            }
            else if (a[i][j] == 2)
            {
                v2.push_back({i, j});
            }
        }
    }

    for (int i = 0; i < (int)v0.size(); i++)
    {
        for (int j = i + 1; j < (int)v0.size(); j++)
        {
            for (int k = j + 1; k < (int)v0.size(); k++)
            {
                a[v0[i].first][v0[i].second] = 1;
                a[v0[j].first][v0[j].second] = 1;
                a[v0[k].first][v0[k].second] = 1;

                ret = max(ret, go());
                memset(visited, 0, sizeof(visited));

                a[v0[i].first][v0[i].second] = 0;
                a[v0[j].first][v0[j].second] = 0;
                a[v0[k].first][v0[k].second] = 0;
            }
        }
    }

    cout << ret << "\n";

    return 0;
}
