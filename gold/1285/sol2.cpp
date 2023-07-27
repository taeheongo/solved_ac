/*
    submission : https://www.acmicpc.net/source/62728091

    i번째 행을 뒤집을 수도 있고 안 뒤집을 수 도 있다.
    즉 모든 행을 다 고려한 경우의 수 2^n 개의 경우의 수가 나오는데
    그 모든 case에 대하여 다시 열을 뒤집는 경우의 수를 고려하면
    2^n * 2^n

    그러나 생각해보면 행을 다 고려하고나면 특정 열은 뒤집을지 안 뒤집을지 이미 결정되어 있기 때문에
    2^n이다.

    T,H 밖에 없기 때문에 이를 1,0 으로 볼 수 있고,
    뒤집는다 = ~연산 이기 때문에 비트 연산을 활용해서 문제를 더 간결하게 풀 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 20;
const int INF = 987654321;

int n, ret = INF;
int a[max_n + 4];
string s;

void go(int idx)
{
    if (idx == n + 1)
    {
        int sum = 0;
        for (int i = 1; i <= 1 << (n - 1); i *= 2)
        {
            int cnt = 0;
            for (int j = 1; j <= n; j++)
            {
                if (a[j] & i)
                    cnt++;
            }
            sum += min(cnt, n - cnt);
        }
        ret = min(sum, ret);
        return;
    }

    go(idx + 1);
    a[idx] = ~a[idx];
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
        cin >> s;
        int val = 1;
        for (char c : s)
        {
            if (c == 'T')
                a[i] |= val;
            val *= 2;
        }
    }

    go(1);

    cout << ret << "\n";

    return 0;
}