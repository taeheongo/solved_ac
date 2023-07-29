/*
    submission : https://www.acmicpc.net/source/64239008

    time: 2^26 * n * (5 ~ 18)

    이 풀이는 26C0 + 26C1 + ... + 26C26 만큼 반복문을 돌아서 비효율적.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, x, ret;
string s_arr[50];
char b[5] = {'a', 'n', 't', 'i', 'c'};

void solve()
{
    if (k < 5)
        return;

    for (int i = 0; i < (1 << 26); i++)
    {
        int cnt = 0;
        bool flag = true;
        for (int j = 0; j < 5; j++)
        {
            if ((i & (1 << (b[j] - 'a'))) == 0)
            {
                flag = false;
                break;
            }
        }

        if (!flag)
            continue;

        int cnt2 = 0;
        for (int j = 0; j < 26; j++)
        {
            if (i & (1 << j))
                cnt2++;
        }

        if (cnt2 != k)
            continue;

        for (int j = 0; j < n; j++)
        {
            int k = 0;
            for (; k < s_arr[j].size(); k++)
            {
                if ((i & (1 << (s_arr[j][k] - 'a'))) == 0)
                    break;
            }

            if (k == s_arr[j].size())
                cnt++;
        }

        ret = max(cnt, ret);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> s_arr[i];
    }

    solve();

    cout << ret << "\n";

    return 0;
}
