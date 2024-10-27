/*
    문제 : https://blog.naver.com/jhc9639/222283814653
    누적합(Prefix sum)

    구간커리 = 누적합 or 펜윅트리
    배열의 요소가 변하지 않는 정적배열 => 누적합
    배열의 요소가 변하는 동적배열 => 펜윅트리

    time : O(n + m)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int nums[100004], psum[100004], cnt;

int main() {
    cin >> n >> m;

    // o(n)
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
        psum[i] = psum[i - 1] + nums[i];
    }

    // o(m)
    while (m--) {
        cin >> a >> b;
        cout << psum[b] - psum[a - 1] << "\n";
    }

    return 0;
}
