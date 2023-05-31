/*
    submission : https://www.acmicpc.net/source/61515548

    문자 shifting 하기
*/

#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    getline(cin, s);

    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] >= 65 && s[i] <= 90)
        {
            s[i] = s[i] - 65 + 13;
            s[i] = s[i] % 26;
            s[i] += 65;
        }

        if (s[i] >= 97 && s[i] <= 122)
        {
            s[i] = s[i] - 97 + 13;
            s[i] = s[i] % 26;
            s[i] += 97;
        }
    }

    cout << s << "\n";

    return 0;
}