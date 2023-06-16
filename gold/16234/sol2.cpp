/*
    submission : https://www.acmicpc.net/source/62134962

    각 connected components의 합을 구하는 과정을 dfs를 돌면서 구해서 반복문 도는 수를 줄여보았다.
    수행시간은 똑같긴함.
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pos;

int n, l, r, ret;
int a[50][50];
bool visited[50][50];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, vector<pos> &v, int &sum)
{
    visited[y][x] = 1;
    v.push_back({y, x});
    sum += a[y][x];

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n)
            continue;
        if (visited[ny][nx])
            continue;

        int gap = abs(a[ny][nx] - a[y][x]);
        if (gap < l || gap > r)
            continue;

        dfs(ny, nx, v, sum);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l >> r;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    do
    {
        memset(visited, 0, sizeof(visited));
        cnt = 0;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                {
                    vector<pos> v;
                    int sum = 0;
                    dfs(i, j, v, sum);

                    if (v.size() >= 2)
                    {
                        for (pos &p : v)
                        {
                            a[p.first][p.second] = sum / v.size();
                        }
                        cnt++;
                    }
                }
            }
        }

        if (cnt >= 1)
        {
            ret++;
        }

    } while (cnt >= 1);

    cout << ret << "\n";

    return 0;
}