#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 크기가 n인 집합의 모든 비트 켜기
    int n = 4;
    cout << (1 << n) - 1 << "\n"; // 1111

    return 0;
}