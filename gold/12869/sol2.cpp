/*
    submission : https://www.acmicpc.net/source/62231528

    가중치 같은 그래프이고 최단 거리를 구한다고 하면 bfs를 써야 한다.

    time <= 180

    체력의 최대치인 {60, 60, 60} 이라고 해도
    아무리 늦어도 180안에 끝난다.
*/
#include <bits/stdc++.h>

using namespace std;

int n;
int nums[3];
int dmg[6][3] = {
    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1},
};

int visited[64][64][64];

typedef struct
{
    int x, y, z;
} pos;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    pos start = {nums[0], nums[1], nums[2]};
    visited[start.x][start.y][start.z] = 1;
    queue<pos> q;
    q.push(start);

    while (q.size())
    {
        int x = q.front().x;
        int y = q.front().y;
        int z = q.front().z;
        q.pop();

        if (visited[0][0][0])
            break;

        for (int i = 0; i < 6; i++)
        {
            int nx = max(x - dmg[i][0], 0);
            int ny = max(y - dmg[i][1], 0);
            int nz = max(z - dmg[i][2], 0);

            if (visited[nx][ny][nz])
                continue;

            visited[nx][ny][nz] = visited[x][y][z] + 1;
            q.push({nx, ny, nz});
        }
    }

    cout << visited[0][0][0] - 1 << "\n";

    return 0;
}