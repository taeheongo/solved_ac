/*
submission : https://www.acmicpc.net/source/61442995

조합을 이용한 풀이 9C7 = 9C2
반복문 2번만 돌리면 되므로 iterative한 방식 풀이가 좋음.
9C4이러면 반복문을 4번을 돌려야 하는데 이럴 때는 recursive한 방식이 좋음.

*/

#include <bits/stdc++.h>

using namespace std;

int a[9], sum = 0;
pair<int, int> ret;

void solve()
{
    for (int i = 0; i < 9; i++)
    {
        sum -= a[i];
        for (int j = i + 1; j < 9; j++)
        {
            if (sum - a[j] == 100)
            {
                ret = {i, j};
                return;
            }
        }
        sum += a[i];
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + 9);
    solve();

    for (int i = 0; i < 9; i++)
    {
        if (i == ret.first || i == ret.second)
        {
            continue;
        }
        cout << a[i] << "\n";
    }

    return 0;
}