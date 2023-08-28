/*
    submission : https://www.acmicpc.net/source/65749561

    구현 문제
        현재 밟고 있는 곳인지 아닌지 체크. => visited
        뒤에 추가도 하고 앞에서 빼기도 해야함 => deque
        방향 회전 => dy, dx

    주의 점:
        2차원 좌표상에서는 오른쪽으로 회전하면 y는 -1이지만 배열의 좌표에서는 +1이다.
        사과를 밟으면 없어지는 부분도 고려해야 함.
*/

#include <bits/stdc++.h>

using namespace std;

const int dy[4] = {0, -1, 0, 1};
const int dx[4] = {-1, 0, 1, 0};

int n, k, l, y, x, t, _t, dir_idx = 2, change_dir_idx;
char c;
int a[100][100];
pair<int, int> change_dir[100];
bool visited[100][100];
deque<pair<int, int>> dq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> y >> x;
        a[--y][--x] = 1;
    }

    cin >> l;
    for (int i = 0; i < l; i++)
    {
        cin >> x >> c;
        change_dir[i] = {x, (c == 'D' ? 1 : 3)};
    }

    visited[0][0] = 1;
    dq.push_back({0, 0});

    while (true)
    {
        t++;
        tie(y, x) = dq.back();

        int ny = y + dy[dir_idx];
        int nx = x + dx[dir_idx];

        if (ny < 0 || ny >= n || nx < 0 || nx >= n || visited[ny][nx])
            break;

        visited[ny][nx] = 1;
        dq.push_back({ny, nx});

        if (a[ny][nx] == 0)
        {
            visited[dq[0].first][dq[0].second] = 0;
            dq.pop_front();
        }
        else
        {
            a[ny][nx] = 0;
        }

        if (change_dir_idx < l)
        {
            tie(_t, x) = change_dir[change_dir_idx];
            if (t == _t)
            {
                dir_idx = (dir_idx + x) % 4;
                change_dir_idx++;
            }
        }
    }

    cout << t << "\n";

    return 0;
}