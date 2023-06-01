/*
    submission : https://www.acmicpc.net/source/61572645

    조금 더 클린한 코드일 줄알았는데 비슷하네.
*/

#include <bits/stdc++.h>

using namespace std;

string s, ret;
int cnt[200];
char mid;

int main()
{
    cin >> s;
    for (char c : s)
    {
        cnt[c]++;
    }

    int odd_num = 0;
    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (cnt[i])
        {
            if (cnt[i] & 1)
            {
                mid = char(i);
                odd_num++;
                cnt[i]--;
            }
        }
        if (odd_num == 2)
        {
            break;
        }
        for (int j = 0; j < cnt[i]; j += 2)
        {
            ret = char(i) + ret;
            ret += char(i);
        }
    }

    if (odd_num == 2)
    {
        cout << "I'm Sorry Hansoo\n";
    }
    else
    {
        if (mid)
        {
            ret.insert(ret.begin() + ret.size() / 2, mid);
        }
        cout << ret << "\n";
    }

    return 0;
}