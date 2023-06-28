#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    // i번째 비트가 켜져있는지 확인하기.
    int s = 18; // 0001 0010
    int i = 1;
    if (s & (1 << i))
        printf("%d번째 비트 on!", i);
    else
        printf("%d번째 비트 off!", i);

    return 0;
}