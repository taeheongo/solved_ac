/*
    submission : https://www.acmicpc.net/source/67204896

    solution1과 논리는 같으나 prefix sum을 사용한 코드.
*/

#include <bits/stdc++.h>

using namespace std;

int p, m, n, num;
long long ret;
int a[1001], b[1001];
int psum_a[2001], psum_b[2001];
int cnt_a[2000001], cnt_b[2000001];

void make(int size, int* arr, int* psum, int* cnt) {
    for (int i = 1; i <= size; i++) {
        cin >> arr[i];
        psum[i] = psum[i - 1] + arr[i];
    }
    for (int i = size + 1; i <= 2 * size; i++) {
        psum[i] = psum[i - 1] + arr[i - size];
    }

    cnt[0] = 1;
    num = accumulate(arr + 1, arr + size + 1, 0);
    cnt[num] = 1;
    for (int i = 0; i < size; i++) {
        for (int s = i + 1; s <= i + size - 1; s++) {
            int num = psum[s] - psum[i];
            cnt[num]++;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> p >> m >> n;

    make(m, a, psum_a, cnt_a);
    make(n, b, psum_b, cnt_b);

    for (int i = 0; i <= p; i++) {
        ret += cnt_a[i] * cnt_b[p - i];
    }

    cout << ret << "\n";

    return 0;
}