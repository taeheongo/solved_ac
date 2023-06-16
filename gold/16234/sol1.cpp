/*
    submission : https://www.acmicpc.net/source/62134363

    time <= N * N * conneted components의 최대개수
     50 * 50 * 1250

    왜 1250이냐면 둘 사이의 거리 d가 l <= d <= r 이어야 하는데
    거리는 최소 두 개의 나라가 있어야 하니까 둘 이상임.
    가장 많은 connected components 의 개수는 모든 connected components가 2개의 원소만으로 이루어졌을 때 일 것임.
*/
#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pos;

int n, l, r, ret;
int a[50][50];
bool visited[50][50];
vector<vector<pos>> vv;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

void dfs(int y, int x, vector<pos> &v)
{
    visited[y][x] = 1;
    v.push_back({y, x});

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

        dfs(ny, nx, v);
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

    do
    {
        memset(visited, 0, sizeof(visited));
        vv.clear();

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (visited[i][j] == 0)
                {
                    vector<pos> v;
                    dfs(i, j, v);

                    if (v.size() >= 2)
                    {
                        vv.push_back(v);
                    }
                }
            }
        }

        for (auto e : vv)
        {
            int sum = 0;
            for (pos &p : e)
            {
                sum += a[p.first][p.second];
            }

            for (pos &p : e)
            {
                a[p.first][p.second] = sum / e.size();
            }
        }

        if (vv.size() >= 1)
        {
            ret++;
        }

    } while (vv.size() != 0);

    cout << ret << "\n";

    return 0;
}