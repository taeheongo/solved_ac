/*
    submission : https://www.acmicpc.net/source/64557211

    time: O( (2^(n*m)) * (n*m) ) <= 100000 * 16

    각 행별로 연속된 1로 가로로 연속된 수의 합
    각 열별로 연속된 0을 세로로 연속된 수의 합

    지도의 모든 경우의 수마다 저 2가지의 합을 더한 값을 비교하면 된다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int a[4][4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf("%d %d", &n, &m);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            scanf("%1d", &a[i][j]);
        }
    }

    for (int num = 0; num < (1 << (m * n)); num++)
    {
        int sum = 0;
        for (int i = 0; i < n; i++)
        {
            int cur = 0;
            for (int j = 0; j < m; j++)
            {
                if ((num & (1 << (i * m + j))) != 0)
                {
                    cur = cur * 10 + a[i][j];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        for (int j = 0; j < m; j++)
        {
            int cur = 0;
            for (int i = 0; i < n; i++)
            {
                if ((num & (1 << (i * m + j))) == 0)
                {
                    cur = cur * 10 + a[i][j];
                }
                else
                {
                    sum += cur;
                    cur = 0;
                }
            }
            sum += cur;
        }

        ret = max(ret, sum);
    }

    cout << ret << "\n";

    return 0;
}