/*
    submission : https://www.acmicpc.net/source/62749187

    H, T로 이루어진 맵을 뒤집는다는 특성 때문에 bit operation을 활용하면 좋은 것이지.
    안 써도 풀 수 있다.

    time : (n / 2) * 2^n = O(2^n)
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 20;
const int INF = 987654321;

int n, ret = INF;
char a[max_n + 4][max_n + 4];
string s;

void go(int idx)
{
    if (idx == n + 1)
    {
        int sum = 0;
        for (int j = 1; j <= n; j++)
        {
            int cnt = 0;
            for (int i = 1; i <= n; i++)
            {
                if (a[i][j] == 'T')
                    cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(sum, ret);
        return;
    }

    go(idx + 1);
    for (int j = 1; j <= n; j++)
    {
        a[idx][j] = a[idx][j] == 'T' ? 'H' : 'T';
    }
    go(idx + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    go(1);

    cout << ret << "\n";

    return 0;
}