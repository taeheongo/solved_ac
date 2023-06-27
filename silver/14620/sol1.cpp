/*
    submission : https://www.acmicpc.net/source/62601619

    time <= 100C3
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10;
const int INF = 987654321;
int n, ret = INF;
int a[max_n + 4][max_n + 4];
bool visited[max_n][max_n];

const int dy[5] = {0, 0, 1, 0, -1};
const int dx[5] = {0, -1, 0, 1, 0};

void go(int y, int x, int sum, int cnt)
{
    if (sum >= ret)
        return;

    if (cnt == 3)
    {
        ret = min(sum, ret);
        return;
    }

    if (x >= n - 1)
    {
        x = 1;
        y++;
    }
    if (y == n - 1)
    {
        return;
    }

    go(y, x + 1, sum, cnt);
    if (!visited[y][x - 1] && !visited[y - 1][x])
    {
        for (int i = 0; i < 5; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            sum += a[ny][nx];
            visited[ny][nx] = 1;
        }

        go(y, x + 2, sum, cnt + 1);

        for (int i = 0; i < 5; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            visited[ny][nx] = 0;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    go(1, 1, 0, 0);

    cout << ret << "\n";

    return 0;
}
