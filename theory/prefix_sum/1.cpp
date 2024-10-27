/*
    문제 : https://blog.naver.com/jhc9639/222283814653

    Brute force
    time : O(n + m(b-a)) <- 최대 10^10 = 100억 -> 시간초과
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
int nums[100004], cnt;

int main() {
    cin >> n >> m;

    // o(n)
    for (int i = 1; i <= n; i++) {
        cin >> nums[i];
    }

    // o(m*(b-a))
    while (m--) {
        cin >> a >> b;
        int sum = 0;
        for (int i = a; i <= b; i++) {
            sum += nums[i];
        }
        cout << sum << "\n";
    }

    return 0;
}
