/*
    submission : https://www.acmicpc.net/source/64988679

    time: O(NlogN)

    서로 다른 양의 정수라고 했으니 이진탐색도 사용가능.
    투 포인터 보다 비효율적.
    매번 이진탐색으로 찾아야해서 정렬을 빼도 O(NlogN)이 걸리지만
    투포인터는 정렬을 빼면 O(N) 임.
*/

#include <bits/stdc++.h>

using namespace std;

int n, x, ret;
int a[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;

    sort(&a[0], &a[n]);

    for (int i = 0; i < n; i++)
    {
        int idx = (int)(lower_bound(&a[0], &a[n], x - a[i]) - &a[0]);

        if (idx == n || a[i] + a[idx] != x)
            continue;

        if (i >= idx)
            break;

        ret++;
    }

    cout << ret << "\n";

    return 0;
}