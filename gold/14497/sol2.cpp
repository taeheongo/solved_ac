/*
    submission : https://www.acmicpc.net/source/62413248

    time : O(M*N)

    solution 1과 같지만 잡기술 몇 개 추가.
    pair<int, int>를 쓰지 않고 int 하나만으로 (y, x) 좌표정보를 표현하는 방법
     1 <= n,m <= 300 인데 300보다 큰 수 1000정도라고 하면

    보관할 때는 n = 1000 * y + x
    꺼낼 때는  y = n / 1000;  x = n % 1000;

    주의점 : 이 문제는 (1,1)부터 시작하는데 이 테크닉을 사용하려면 (0, 0)부터 시작한다.
    왜냐하면 10진수 체계는 0~9 그리고 10~19 이렇게 0부터 시작해서 9 그리고 더 커지면 다음 자리수로 올라가는 구조.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, y, x;
char a[304][304];
int visited[304][304];

const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {-1, 0, 1, 0};

// 디버그 코드
void print()
{
    cout << "\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << visited[i][j];
        }
        cout << "\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int x1, y1, x2, y2;

    cin >> n >> m;
    cin >> y1 >> x1 >> y2 >> x2;
    y1--;
    x1--;
    y2--;
    x2--;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }

    queue<int> q;
    queue<int> q_tmp;

    q.push(1000 * y1 + x1);
    visited[y1][x1] = 1;

    int depth = 0;
    while (a[y2][x2] != '0')
    {
        depth++;

        while (q.size())
        {
            y = q.front() / 1000;
            x = q.front() % 1000;
            q.pop();

            for (int i = 0; i < 4; i++)
            {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                    continue;

                if (visited[ny][nx])
                    continue;

                visited[ny][nx] = depth;
                if (a[ny][nx] == '0')
                {
                    q.push(1000 * ny + nx);
                }
                else
                {
                    a[ny][nx] = '0';
                    q_tmp.push(1000 * ny + nx);
                }
            }
        }

        // print();
        swap(q, q_tmp);
    }

    cout << visited[y2][x2] << "\n";

    return 0;
}