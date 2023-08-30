/*
    submission : https://www.acmicpc.net/source/65784683

    구현을 물어보는 문제.
        순열 + rotate 2d array

    time <= 6P6 * n * m
*/
#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};

int n, m, k, ret = INF;
int a[54][54];
vector<int> v;

struct R
{
    int r, c, s;
};
R rotate_oeration[6];

/*
    p1 (sy, sx)                p2 (sy, ex)

    p3 (ey, sx)                p4 (ey, ex)
*/
void rotate_p(int idx, int a[54][54])
{
    if (idx >= k)
        return;

    R &ro = rotate_oeration[idx];
    int sy = ro.r - ro.s - 1;
    int sx = ro.c - ro.s - 1;
    int ey = ro.r + ro.s - 1;
    int ex = ro.c + ro.s - 1;

    while (sy < ey && sx < ex)
    {
        int dir_idx = 0;
        int y = sy, x = sx;
        int tmp1 = a[y][x], tmp2;

        while (dir_idx < 4)
        {
            int ny = y + dy[dir_idx];
            int nx = x + dx[dir_idx];

            tmp2 = a[ny][nx];
            a[ny][nx] = tmp1;
            tmp1 = tmp2;

            pair<int, int> p = {ny, nx};
            pair<int, int> p1 = {sy, sx};
            pair<int, int> p2 = {sy, ex};
            pair<int, int> p3 = {ey, ex};
            pair<int, int> p4 = {ey, sx};

            if (p == p1 || p == p2 || p == p3 || p == p4)
            {
                dir_idx++;
            }

            y = ny;
            x = nx;
        }

        sy++;
        sx++;
        ey--;
        ex--;
    }
}

int get_value(int a[54][54])
{
    int ret = INF;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < m; j++)
        {
            sum += a[i][j];
        }
        ret = min(sum, ret);
    }

    return ret;
}

// kPk
void perm(int start_idx)
{
    if (start_idx == k)
    {
        int tmp[54][54];
        memcpy(tmp, a, sizeof(a));

        for (int idx : v)
        {
            rotate_p(idx, tmp);
        }

        ret = min(ret, get_value(tmp));

        return;
    }

    for (int i = start_idx; i < k; i++)
    {
        swap(v[i], v[start_idx]);
        perm(start_idx + 1);
        swap(v[i], v[start_idx]);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m >> k;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    int r, c, s;
    for (int i = 0; i < k; i++)
    {
        cin >> r >> c >> s;
        rotate_oeration[i] = {r, c, s};
    }

    for (int i = 0; i < k; i++)
    {
        v.push_back(i);
    }

    perm(0);

    cout << ret << "\n";

    return 0;
}