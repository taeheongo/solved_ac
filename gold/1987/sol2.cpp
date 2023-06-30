/*
    submission : https://www.acmicpc.net/source/62775288

    time: O(3^26)

    solution 1과 논리는 같음. 구현과정에서 알파벳은 26개고 int는 32bits니까
    bit operation으로 표현가능.
*/
#include <bits/stdc++.h>

using namespace std;

int r, c;

const int max_n = 20;
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int alp;
char a[max_n + 4][max_n + 4];

int dfs(int y, int x)
{
    // cout << y << ", " << x << "\n"; // 디버그 코드
    alp |= (1 << (int)(a[y][x] - 'A'));

    int cnt = 0;
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= r || nx < 0 || nx >= c)
            continue;

        if (alp & (1 << (int)(a[ny][nx] - 'A')))
            continue;

        cnt = max(cnt, dfs(ny, nx));
    }

    alp &= ~(1 << (int)(a[y][x] - 'A'));

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
