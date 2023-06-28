#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // 최하위 켜져있는 비트 찾기
    int s = 20; // 0001 0100
    int i = s & -s;

    cout << i << "\n"; // 0000 0100

    return 0;
}