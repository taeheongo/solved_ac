/*
    submission : https://www.acmicpc.net/source/62533605

    time: O(3^26)
*/
#include <bits/stdc++.h>

using namespace std;

int r, c;

const int max_n = 20;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

bool visited[max_n + 4][max_n + 4];
bool alp[26];
char a[max_n + 4][max_n + 4];

int dfs(int y, int x)
{
    // cout << y << ", " << x << "\n"; // 디버그 코드
    visited[y][x] = 1;
    alp[a[y][x] - 'A'] = 1;

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        if (visited[ny][nx] || alp[a[ny][nx] - 'A'])
            continue;

        cnt = max(cnt, dfs(ny, nx));
    }

    visited[y][x] = 0;
    alp[a[y][x] - 'A'] = 0;

    return cnt + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c;

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
        }
    }

    cout << dfs(0, 0) << "\n";

    return 0;
}