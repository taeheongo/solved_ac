/*
    submission : https://www.acmicpc.net/source/62775516

    time: O(3^26)

    solution 2에서 dfs에 매개변수로 alp를 넘겨주면 원복부분을 할 필요가 없음.
*/
#include <bits/stdc++.h>

using namespace std;

int r, c;

const int max_n = 20;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

char a[max_n + 4][max_n + 4];

int dfs(int y, int x, int alp)
{
    // cout << y << ", " << x << "\n"; // 디버그 코드

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        if (alp & (1 << (int)(a[ny][nx] - 'A')))
            continue;
        int tmp = (1 << (int)(a[ny][nx] - 'A'));
        cnt = max(cnt, dfs(ny, nx, alp | tmp));
    }

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

    cout << dfs(0, 0, 1 << (int)(a[0][0] - 'A')) << "\n";

    return 0;
}
