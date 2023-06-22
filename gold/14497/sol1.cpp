/*
    submission : https://www.acmicpc.net/source/62412649

    time : O(M*N)

    bfs + q를 2개쓰는 잡기술.

    1 <= n,m <= 300 조심
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, y, x, depth = 1;
char a[304][304];
bool visited[304][304];
pair<int, int> pos1, pos2;
bool flag = false;

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

// 디버그 코드
void print()
{
    cout << "\n";
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cout << a[i][j];
        }
        cout << "\n";
    }
}

void go(int y, int x, queue<pair<int, int>> &q)
{
    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 1 || ny > n || nx < 1 || nx > m)
            continue;

        if (visited[ny][nx])
            continue;

        switch (a[ny][nx])
        {
        case '1':
            a[ny][nx] = '0';
            visited[ny][nx] = 1;
            q.push({ny, nx});
            break;
        case '0':
            visited[ny][nx] = 1;
            go(ny, nx, q);
            break;
        case '#':
            flag = true;
            return;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;
    cin >> pos1.first >> pos1.second >> pos2.first >> pos2.second;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    queue<pair<int, int>> q;
    queue<pair<int, int>> q2;
    q.push(pos1);
    visited[pos1.first][pos1.second] = 1;

    while (q.size())
    {
        tie(y, x) = q.front();
        q.pop();

        go(y, x, q2);

        // print();

        if (flag)
            break;

        if (q.empty())
        {
            while (q2.size())
            {
                q.push(q2.front());
                q2.pop();
            }
            depth++;
        }
    }

    if (flag)
        cout << depth << "\n";

    return 0;
}
