#include <bits/stdc++.h>

using namespace std;

int n, m, num, psum[100004], sum;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> num;
        psum[i] = psum[i - 1] + num;
    }

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        sum = psum[r] - psum[l - 1];
        printf("sum : %d\n", sum);
    }

    return 0;
}

/*
    최대 : 10^5 + 10^5
*/