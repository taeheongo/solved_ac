/*
    submission : https://www.acmicpc.net/source/61595683

    정렬 + 이분탐색

    time: O(NlogN)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int a[150000];

int main()
{
    cin >> n >> m;

    if (m > 200000)
    {
        cout << 0 << "\n";
    } // 시간초과가 타이트할 경우

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    sort(a, a + n);

    for (int i = 0; i <= n - 1; i++)
    {
        int x = *lower_bound(a + i + 1, a + n, m - a[i]);

        if (x == m - a[i])
        {
            ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}
