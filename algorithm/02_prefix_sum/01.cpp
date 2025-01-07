/*
    누적합(prefix sum)

    구간에 대한 쿼리 => 트리(세그먼트, 펜윅트리), 누적합
        요소가 바뀌지 않는다면 -> 누적합
        요소가 바뀌면 트리 -> 트리(세그먼트, 펜윅트리)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a[100004], sum;

int main() {
    cin >> n >> m;

    for (int i = 1; i <= n; i++) cin >> a[i];

    int l, r;
    for (int i = 0; i < m; i++) {
        cin >> l >> r;
        sum = 0;
        for (int j = l; j <= r; j++) sum += a[j];
        printf("sum : %d\n", sum);
    }

    return 0;
}

/*
    1 <= N <= 100,000
    1 <= M <= 100,000
    1 <= L <= R <= N

    최대 : 10^5 + 10^5 * 10^5
*/