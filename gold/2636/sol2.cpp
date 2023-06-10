/*
    submission : https://www.acmicpc.net/source/61944253

    로직은 같으나 더 깔끔한 코드.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];
vector<int> ret;
vector<pair<int, int>> pos_c;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void solve(int y, int x, int &cnt)
{
    visited[y][x] = 1;

    if (a[y][x] == 1)
    {
        a[y][x] = 'c';
        pos_c.push_back({y, x});
        cnt++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= m)
            continue;

        if (visited[ny][nx])
            continue;

        solve(ny, nx, cnt);
    }
}

void clear()
{
    for (auto e : pos_c)
    {
        a[e.first][e.second] = 0;
    }
    pos_c.clear();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    int total = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == 1)
                total++;
        }
    }

    while (total > 0)
    {
        int cnt = 0;
        solve(0, 0, cnt);
        ret.push_back(cnt);
        total -= cnt;
        clear();
        memset(visited, 0, sizeof(visited));
    }

    cout << ret.size() << "\n";
    cout << ret[ret.size() - 1] << "\n";

    return 0;
}
