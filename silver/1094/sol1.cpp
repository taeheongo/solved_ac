/*
    submission : https://www.acmicpc.net/source/64273813
*/

#include <bits/stdc++.h>

using namespace std;

int len = 64, cnt = 1, x, cur = 64;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> x;

    while (len != x)
    {
        cur /= 2;
        cnt++;

        if ((len - cur) >= x)
        {
            len -= cur;
            cnt--;
        }
    }

    cout << cnt << "\n";

    return 0;
}