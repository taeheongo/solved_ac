/*
    submission : https://www.acmicpc.net/source/61478426

    counting -> 맵 또는 배열.
*/

#include <bits/stdc++.h>

using namespace std;

int cnt[26], n, num;
string s;

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> s;

        cnt[s[0] - 'a']++;
    }

    for (int i = 0; i < 26; i++)
    {
        if (cnt[i] >= 5)
        {
            cout << char(i + 97);
            num++;
        }
    }

    if (num == 0)
    {
        cout << "PREDAJA\n";
    }

    return 0;
}