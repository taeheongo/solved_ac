/*
    submission : https://www.acmicpc.net/source/65568550

    time : O(r * c * t)

    논리는 어렵지 않으나 구현이 빡센 문제.
*/
#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int r, c, t, ret;
int a[50][50], cnt[50][50], b[50][50];
vector<pair<int, int>> v;

void calcuate_cnt()
{
    for (int y = 0; y < r; y++)
    {
        for (int x = 0; x < c; x++)
        {
            int diffused_amount = a[y][x] / 5;
            if (diffused_amount == 0)
                continue;

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= r || nx < 0 || nx >= c || a[ny][nx] == -1)
                    continue;

                cnt[ny][nx] += diffused_amount;
                cnt[y][x] -= diffused_amount;
            }
        }
    }
}

void diffuse()
{
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            a[i][j] += cnt[i][j];
            cnt[i][j] = 0;
        }
    }
}

void print()
{
    cout << "\n";
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void shift()
{
    memcpy(b, a, sizeof(a));

    for (int j = 2; j < c; j++)
    {
        b[v[0].first][j] = a[v[0].first][j - 1];
        b[v[1].first][j] = a[v[1].first][j - 1];
    }

    for (int i = v[0].first - 1; i >= 0; i--)
    {
        b[i][c - 1] = a[i + 1][c - 1];
    }

    for (int i = v[1].first + 1; i < r; i++)
    {
        b[i][c - 1] = a[i - 1][c - 1];
    }

    for (int j = c - 2; j >= 0; j--)
    {
        b[0][j] = a[0][j + 1];
        b[r - 1][j] = a[r - 1][j + 1];
    }

    for (int i = 1; i < v[0].first; i++)
    {
        b[i][0] = a[i - 1][0];
    }

    for (int i = r - 2; i > v[1].first; i--)
    {
        b[i][0] = a[i + 1][0];
    }

    b[v[0].first][1] = 0;
    b[v[1].first][1] = 0;

    swap(a, b);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> r >> c >> t;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];
            if (a[i][j] == -1)
            {
                v.push_back({i, j});
            }
        }
    }
    while (t--)
    {
        // 1. 순회하면서 a[i][j]에 대하여 +, -를 계산해서 cnt[i][j]에 저장.
        calcuate_cnt();

        // 2. 맵을 다시 순회하면서 cnt[i][j]를 적용.
        diffuse();

        // print(); // 디버그

        // 3. 공기청정기로 인한 shifting.
        shift();

        // print(); // 디버그
    }

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (a[i][j] > 0)
                ret += a[i][j];
        }
    }

    cout << ret << "\n";

    return 0;
}