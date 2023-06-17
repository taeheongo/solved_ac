/*
    submission : https://www.acmicpc.net/source/62200784

    이 문제 어려운 점
        1. 불은 네방향으로 확산된다. => 이말이 있기 때문에 불은 무조건 인접4방향으로 최단거리로 가게 됨.

        2. 문제를 읽어보면 지훈이는 무조건 하나만 주어진다고 했음. 그런데 불에 대한 언급은 없음.
            그러면서 또 예제는 불이 하나만 있는 경우만 주어서 불이 하나 이겠거니 할 수 있음.

        3. 불이 아예 없을 수도 있다.
            memset(fire, -1, sizeof(fire));
            처음에 이렇게 초기화를 했는데 실패.
            불이 아예 존재하지 않는 경우는 불보다 지훈이의 최단거리가 항상 크기 때문에 ret = 0으로 만 나옴.
                => 그래서 0 이아닌 INF로 초기화를 해야 하는거임.
*/

#include <bits/stdc++.h>

using namespace std;

int r, c, ret, y, x;
char a[1004][1004];
pair<int, int> pos_j;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

int person[1004][1004]; // 지훈이 최단거리
int fire[1004][1004];   // 불 최단거리
const int INF = 987654321;

bool check(int y, int x)
{
    return 0 <= y && y < r && 0 <= x && x < c;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> r >> c;
    queue<pair<int, int>> q;
    fill(&fire[0][0], &fire[0][0] + 1004 * 1004, INF); // 불이 없을 수도 있으므로 반드시 INF로 초기화.

    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> a[i][j];

            if (a[i][j] == 'J')
            {
                pos_j = {i, j};
            }
            else if (a[i][j] == 'F')
            {
                // 불이 여러개 존재 할 수 있으므로 반드시 여기서 enqueue를 해줘야 함.
                q.push({i, j});
                fire[i][j] = 1;
            }
        }
    }

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!check(ny, nx))
                continue;
            if (fire[ny][nx] != INF || a[ny][nx] == '#')
                continue;

            fire[ny][nx] = fire[y][x] + 1;
            q.push({ny, nx});
        }
    }

    person[pos_j.first][pos_j.second] = 1;
    q.push(pos_j);

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        if (x == 0 || y == 0 || x == c - 1 || y == r - 1)
        {
            ret = person[y][x];
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (!check(ny, nx))
                continue;
            if (person[ny][nx] || a[ny][nx] == '#')
                continue;

            person[ny][nx] = person[y][x] + 1;

            if (person[ny][nx] >= fire[ny][nx])
                continue;

            q.push({ny, nx});
        }
    }

    if (ret)
        cout << ret << "\n";
    else
        cout << "IMPOSSIBLE\n";

    return 0;
}