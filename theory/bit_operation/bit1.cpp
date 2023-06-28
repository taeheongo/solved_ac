#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // i번째 비트 off
    int s = 18; // 0001 0010
    int i = 1;
    s &= ~(1 << i);
    cout << s << "\n"; // 0001 0000

    // i번째 비트 on
    s |= 1 << i;
    cout << s << "\n"; // 0001 0010

    return 0;
}