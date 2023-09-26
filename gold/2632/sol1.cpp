/*
    submission : https://www.acmicpc.net/source/67177431

    prefix sum + 구현 (prefix sum의 개념은 사용하지만 prefix sum을 사용하지는
   않았음.)
    하나도 고르지 않는 경우의 수는 1개임.
    전체 다 더하는 경우의 수도 1개임.

    time : O(m^2 + n^2 + p) <= 10^6 + 10^6 + 2*10^6

        m
        +m-1
        +m-2
        ..
        +1
            = 약 m^2

        nC0
        + nC1
        ..
        + nCn
            = 약 n^2
*/

#include <bits/stdc++.h>

using namespace std;

int p, m, n;
long long ret;
int a[2004];
int b[2004];
int cnt_a[2000001], cnt_b[2000001];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> m >> n;

    for (int i = 0; i < m; i++) {
        cin >> a[i];
        a[i + m] = a[i];
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
        b[i + n] = b[i];
    }

    cnt_a[0] = 1;
    int _sum = accumulate(a, a + m, 0);
    cnt_a[_sum] = 1;
    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = i; j < i + m - 1; j++) {
            sum += a[j];
            cnt_a[sum]++;
        }
    }

    cnt_b[0] = 1;
    _sum = accumulate(b, b + n, 0);
    cnt_b[_sum] = 1;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < i + n - 1; j++) {
            sum += b[j];
            cnt_b[sum]++;
        }
    }

    for (int i = 0; i <= p; i++) {
        ret += cnt_a[i] * cnt_b[p - i];
    }

    cout << ret << "\n";

    return 0;
}
