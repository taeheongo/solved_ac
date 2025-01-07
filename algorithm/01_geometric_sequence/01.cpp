/*
    등비수열(geometric sequence)의 합
*/

#include <bits/stdc++.h>

using namespace std;

int N, cnt, nums[1004], sum;

int go(int l, int r) {
    cnt++;
    if (l == r) return l;  // 중단조건

    int mid = (l + r) / 2;

    return go(l, mid) + go(mid + 1, r);
}

int main() {
    cin >> N;

    for (int i = 1; i <= N; i++) nums[i - 1] = i;

    sum = go(0, N - 1);

    printf("sum : %d, cnt : %d\n", sum, cnt);

    return 0;
}

/*
 N:5 cnt:9
 N:6 cnt:11
 N:7 cnt:13

 1 2 3 4 5 6 7 8
 l             r
 l     r l     r
 l r l r l r l r
 l l l l l l l l

 1 + 2 + 4 + 8

 등비수열의 합 = a(r^N - 1) / (r-1)
              = (2^(log2(N)+1) - 1) / (2 - 1)
              = 2N - 1

 time complexity : O(N)
*/