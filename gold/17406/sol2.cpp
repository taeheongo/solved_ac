/*
    submission : https://www.acmicpc.net/source/65844055

    내장함수 rotate를 사용해서 right rotation을 하는 방식.
    그 외 논리는 같음.
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
const int dy2[4] = {1, 0, -1, 0};
const int dx2[4] = {0, 1, 0, -1};

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
    vector<int> v_i;

    for (int s = 1; s <= ro.s; s++)
    {
        int sy = ro.r - s - 1;
        int sx = ro.c - s - 1;
        int ey = ro.r + s - 1;
        int ex = ro.c + s - 1;

        pair<int, int> p = {sy, sx};
        pair<int, int> p1 = {sy, sx};
        pair<int, int> p2 = {sy, ex};
        pair<int, int> p3 = {ey, ex};
        pair<int, int> p4 = {ey, sx};

        int dir_idx = 0;
        while (dir_idx < 4)
        {
            p.first += dy[dir_idx];
            p.second += dx[dir_idx];
            if (p == p1 || p == p2 || p == p3 || p == p4)
            {
                dir_idx++;
            }
            v_i.push_back(a[p.first][p.second]);
        }

        // right rotation
        rotate(v_i.begin(), v_i.begin() + v_i.size() - 1, v_i.end());

        dir_idx = 0;
        while (dir_idx < 4)
        {
            a[p.first][p.second] = v_i.back();
            v_i.pop_back();
            p.first += dy2[dir_idx];
            p.second += dx2[dir_idx];
            if (p == p1 || p == p2 || p == p3 || p == p4)
            {
                dir_idx++;
            }
        }
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