/*
    등차수열의 합 = n(a + l)/2
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt;

int main() {
    cin >> n;
    int a = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            a += i + j;
            cnt++;
        }
    }

    cout << a << "\n";
    cout << "cnt : " << cnt << "\n";

    return 0;
}

/*
      0 1 2 ... n-1
    0
    1 x
    2 x x
    3 x x x

    n = 1 -> cnt : 0
    n = 2 -> cnt : 0 + 1 = 1
    n = 3 -> cnt : 0 + 1 + 2 = 3
    n = 4 -> cnt : 0 + 1 + 2 + 3 = 6
    n = 5 -> cnt : 0 + 1 + 2 + 3 + 4 = 10
    ...

    time : n(0 + n-1)/2 => n^2
*/