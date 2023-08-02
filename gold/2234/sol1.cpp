/*
    submisssion : https://www.acmicpc.net/source/64326079

    time : O(m * n)

    3번째 값을 구할때도 dfs를 했는데 그럴 필요가 없다.
    sol2에 이를 개선함.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 50;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int n, m, ret1, ret2, ret3;
int a[max_n + 4][max_n + 4];
bool visited[max_n + 4][max_n + 4];

int dfs(int y, int x)
{
    int cnt = 1;
    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;

        if (visited[ny][nx])
            continue;

        if (a[y][x] & (1 << i))
            continue;

        cnt += dfs(ny, nx);
    }

    return cnt;
}

vector<int> solve()
{
    vector<int> ret(2, 0);

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                ret[0]++;
                ret[1] = max(ret[1], dfs(i, j));
            }
        }
    }

    memset(visited, 0, sizeof(visited));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    vector<int> ret = solve();
    ret1 = ret[0];
    ret2 = ret[1];

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (visited[i][j] == 0)
            {
                if (a[i][j] & (1 << 2))
                {
                    a[i][j] &= ~(1 << 2);
                    vector<int> ret = solve();
                    ret3 = max(ret3, ret[1]);
                    a[i][j] |= 1 << 2;
                }

                if (a[i][j] & (1 << 3))
                {
                    a[i][j] &= ~(1 << 3);
                    vector<int> ret = solve();
                    ret3 = max(ret3, ret[1]);
                    a[i][j] |= 1 << 3;
                }
            }
        }
    }

    cout << ret1 << "\n";
    cout << ret2 << "\n";
    cout << ret3 << "\n";

    return 0;
}