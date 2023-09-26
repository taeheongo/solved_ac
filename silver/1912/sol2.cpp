/*
    submission : https://www.acmicpc.net/source/67207683

    연속 합이 음수면 그냥 버리고 양수면 안고간다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, ret = -1001, sum, num;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> num;
        sum += num;
        ret = max(ret, sum);
        if (sum < 0) {
            sum = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}