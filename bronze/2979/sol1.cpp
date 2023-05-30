/*
    submission : https://www.acmicpc.net/source/61476767

    counting -> 맵 또는 배열.

    시작 시간과 끝시간을 구간으로 생각하면 생각할 게 많아진다.
    배열을 전체 시간을 잡고 각 시간마다 ++을 해주는 게 맞음.
*/

#include <bits/stdc++.h>

using namespace std;

int a, b, c;
int cnt[100], s, e, ret;

int main()
{
    cin >> a >> b >> c;
    for (int i = 0; i < 3; i++) // 미만으로 해야함. 중요.
    {
        cin >> s >> e;
        for (int j = s; j < e; j++)
        {
            cnt[j]++;
        }
    }

    for (int i = 0; i < 100; i++)
    {
        if (cnt[i])
        {
            if (cnt[i] == 1)
                ret += a;
            else if (cnt[i] == 2)
                ret += b * 2;
            else
                ret += c * 3;
        }
    }

    cout << ret << "\n";

    return 0;
}