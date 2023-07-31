/*
    submission : https://www.acmicpc.net/source/64277814
*/

#include <bits/stdc++.h>

using namespace std;

int x, cnt;

int main()
{
    cin >> x;

    while (x)
    {
        if (x & 1)
        {
            cnt++;
        }

        x = x >> 1;
    }
    cout << cnt << "\n";

    return 0;
}