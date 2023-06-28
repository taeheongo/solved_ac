#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // i번째 비트 xor
    int s = 18; // 0001 0010
    int i = 0;
    s ^= 1 << i;
    cout << s << "\n"; // 0001 0011

    return 0;
}
/*
0001 0010
0000 0001

0001 0011
*/