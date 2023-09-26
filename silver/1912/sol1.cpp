/*
    submission : https://www.acmicpc.net/source/67206490

    시간초과

    무지성으로 prefix sum을 쓰면 안된다.
    time: O(n^2) => 최대 10^10
*/

#include <bits/stdc++.h>

using namespace std;

int n, ret = -987654321;
int a[100004], psum[100004];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        psum[i] = psum[i - 1] + a[i];
    }

    for (int i = 0; i < n; i++) {
        for (int s = i + 1; s <= n; s++) {
            ret = max(psum[s] - psum[i], ret);
        }
    }

    cout << ret << "\n";

    return 0;
}