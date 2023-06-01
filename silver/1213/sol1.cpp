/*
    submission : https://www.acmicpc.net/source/61571001

    palindrome 만들기.
    counting -> 맵 또는 배열.
*/

#include <bits/stdc++.h>

using namespace std;

string s, ret;
int cnt[26];

int main()
{
    cin >> s;
    for (int i = 0; i < s.size(); i++)
    {
        cnt[s[i] - 'A']++;
    }

    int odd_num = 0;
    int odd_idx = 0;
    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] % 2 == 1)
        {
            odd_num++;
            odd_idx = i;
        }
    }

    if (odd_num >= 2)
    {
        cout << "I'm Sorry Hansoo\n";
    }
    else
    {
        for (int i = 0; i < 26; i++)
        {
            int num = cnt[i] / 2;
            for (int j = 0; j < num; j++)
            {
                ret += char(i + 'A');
            }
        }

        string s2 = ret;
        if (odd_num == 1)
        {
            ret += char(odd_idx + 'A');
        }
        reverse(s2.begin(), s2.end());
        ret += s2;

        cout << ret << "\n";
    }

    return 0;
}