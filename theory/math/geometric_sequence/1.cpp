/*
    등비수열 합 = a(r^n-1) / (r-1)
*/

#include <bits/stdc++.h>

using namespace std;

int n, a[1004], cnt;

int go(int l, int r) {
    cnt++;

    if (l == r) return a[l];

    int mid = (l + r) / 2;
    int sum = go(l, mid) + go(mid + 1, r);

    return sum;
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        a[i - 1] = i;
    }

    int sum = go(0, n - 1);
    cout << "cnt : " << cnt << "\n";
    cout << "sum : " << sum << "\n";

    return 0;
}

/*
    n = 8

    1 2 3 4 5 6 7 8
    l     r l     r => 2
    l r l r l r l r => 4
    l l l l l l l l => 8


    2 * (2^(logn) - 1)/(2 - 1) + 1
    2n - 1 => 15 => O(N)

    n = 2 => 3
    n = 4 => 7
    n = 6 => 11
    n = 8 => 15
*/