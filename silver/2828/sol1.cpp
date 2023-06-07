/*
    submission : https://www.acmicpc.net/source/61835963

    그냥 구현력을 묻는 문제.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, t, p, ret;

int main()
{
    cin >> n >> m >> t;

    int s = 1;
    while (t--)
    {
        cin >> p;

        int e = s + m - 1;
        if (p < s)
        {
            ret += s - p;
            s -= s - p;
        }
        else if (p > e)
        {
            ret += p - e;
            s += p - e;
        }
    }

    cout << ret << "\n";

    return 0;
}