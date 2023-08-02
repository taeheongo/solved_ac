/*
    submission : https://www.acmicpc.net/source/64435083

    time: O(m*n)

    3번째 값을 구할때는 dfs를 할 필요가 없다.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 50;
const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int n, m, ret1, ret2, ret3;
int a[max_n + 4][max_n + 4];
int visited[max_n + 4][max_n + 4];
int cnt_comp[2504];

int dfs(int y, int x, int num)
{
    visited[y][x] = num;
    int cnt = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= m || nx < 0 || nx >= n)
            continue;
        if (visited[ny][nx] || (a[y][x] & (1 << i)))
            continue;

        cnt += dfs(ny, nx, num);
    }

    return cnt;
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

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {
                ret1++;
                cnt_comp[ret1] = dfs(i, j, ret1);
                ret2 = max(ret2, cnt_comp[ret1]);
            }
        }
    }

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i + 1 < m)
            {
                int a = visited[i + 1][j];
                int b = visited[i][j];

                if (a != b)
                {
                    ret3 = max(ret3, cnt_comp[a] + cnt_comp[b]);
                }
            }

            if (j + 1 < n)
            {
                int a = visited[i][j + 1];
                int b = visited[i][j];

                if (a != b)
                {
                    ret3 = max(ret3, cnt_comp[a] + cnt_comp[b]);
                }
            }
        }
    }

    cout << ret1 << "\n";
    cout << ret2 << "\n";
    cout << ret3 << "\n";

    return 0;
}