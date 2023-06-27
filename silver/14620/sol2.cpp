/*
    submission : https://www.acmicpc.net/source/62601619

    로직은 같고 구현방식만 약간 다름.
    코드 라인 수도 줄고, 함수호출도 더 적어짐.
    이 문제에서는 큰 차이가 없지만.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 10;
const int INF = 987654321;
int n, ret = INF;
int a[max_n + 4][max_n + 4];
bool visited[max_n][max_n];

const int dy[5] = {0, 0, 1, 0, -1};
const int dx[5] = {0, -1, 0, 1, 0};

void go(int y, int x, int sum, int cnt)
{
    if (sum >= ret)
        return;

    if (cnt == 3)
    {
        ret = min(sum, ret);
        return;
    }

    for (int i = y; i < n - 1; i++)
    {
        int j = i == y ? x : 1;
        for (; j < n - 1; j++)
        {
            if (!visited[i][j - 1] && !visited[i - 1][j])
            {
                for (int k = 0; k < 5; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    sum += a[ny][nx];
                    visited[ny][nx] = 1;
                }

                go(i, j + 2, sum, cnt + 1);

                for (int k = 0; k < 5; k++)
                {
                    int ny = i + dy[k];
                    int nx = j + dx[k];

                    visited[ny][nx] = 0;
                    sum -= a[ny][nx];
                }
            }
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    go(1, 1, 0, 0);

    cout << ret << "\n";

    return 0;
}
