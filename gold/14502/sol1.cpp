/*
    submission : https://www.acmicpc.net/source/61936642

   time: (n*m comb 3) * (n*m)
   n*m의 최대개수 = 64

   64 comb 3 = 64! / (3! * 6*5*4) = 41,664
   41664 * 64 = 2백만 ~ 3백만

   천만 밑으로는 brute force 가능.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
int a[8][8];
bool visited[8][8];
int ret = 0;
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
        {
            continue;
        }

        if (visited[ny][nx] || a[ny][nx] == 1)
        {
            continue;
        }

        dfs(ny, nx, val);
    }
}

void go()
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
    ret = max(ret, val);                                     // 안전한 영역의 최댓값
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

    int x1, y1, x2, y2, x3, y3;
    for (int i = 0; i < (int)v0.size(); i++)
    {
        tie(y1, x1) = v0[i];
        a[y1][x1] = 1;
        for (int j = i + 1; j < (int)v0.size(); j++)
        {
            tie(y2, x2) = v0[j];
            a[y2][x2] = 1;
            for (int k = j + 1; k < (int)v0.size(); k++)
            {
                tie(y3, x3) = v0[k];
                a[y3][x3] = 1;

                go();
                memset(visited, 0, sizeof(visited));

                a[y3][x3] = 0;
            }
            a[y2][x2] = 0;
        }
        a[y1][x1] = 0;
    }

    cout << ret << "\n";

    return 0;
}
