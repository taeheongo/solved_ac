/*
    submission : https://www.acmicpc.net/source/61943808

    처음에는 치즈가 들어갈 수 없는 가장자리 전부를 solve의 시작점으로 잡았었다.
    (이렇게 해도 통과는 된다. https://www.acmicpc.net/source/61943808)

    그런데 가장자리는 치즈가 들어갈 수 없기 때문에 전부 0이라는 것.
    따라서 solve(0, 0)만해도 된다.
    주석 부분은 디버깅코드

    xxxxxxx
    x     x
    x     x
    xxxxxxx
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[100][100];
bool visited[100][100];
vector<int> ret;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, int &cnt)
{
    if (a[y - 1][x] == 0 || a[y][x + 1] == 0 || a[y + 1][x] == 0 || a[y][x - 1] == 0)
    {
        a[y][x] = 'c';
        cnt++;
    }

    visited[y][x] = 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n - 1 || nx < 0 || nx >= m - 1)
            continue;

        if (visited[ny][nx] || a[ny][nx] == 0)
            continue;

        dfs(ny, nx, cnt);
    }
}

int solve(int y, int x)
{
    int cnt = 0;

    a[y][x] = 'c';
    dfs(y, x, cnt);

    return cnt;
}

void clear()
{
    // cout << "\n\n";

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (a[i][j] == 'c')
            {
                // cout << (char)a[i][j] << " ";
                a[i][j] = 0;
            }
            // else
            // {
            //     cout << a[i][j] << " ";
            // }
        }
        // cout << "\n";
    }
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

    while (total == 0)
    {
        int cnt = 0;
        int i = 1, j = 0;
        for (; j < m - 1; j++)
        {
            if (a[i][j] == 1)
            {
                cnt += solve(i, j);
            }
        }
        i = n - 2;
        j = 1;
        for (; j < m - 1; j++)
        {
            if (a[i][j] == 1)
            {
                cnt += solve(i, j);
            }
        }
        i = 1;
        j = 1;
        for (; i < n - 1; i++)
        {
            if (a[i][j] == 1)
            {
                cnt += solve(i, j);
            }
        }

        i = 1;
        j = m - 1;
        for (; i < n - 1; i++)
        {
            if (a[i][j] == 1)
            {
                cnt += solve(i, j);
            }
        }

        ret.push_back(cnt);
        total -= cnt;
        clear();
        memset(visited, 0, sizeof(visited));
    }

    cout << ret.size() << "\n";
    cout << ret[ret.size() - 1] << "\n";

    return 0;
}