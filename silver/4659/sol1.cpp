/*
    submission : https://www.acmicpc.net/source/61837769

    구현
*/

#include <bits/stdc++.h>

using namespace std;

string s;

bool is_vowel(char c)
{
    return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
}

int main()
{
    while (cin >> s)
    {
        if (s == "end")
            break;

        bool flag1 = false, flag2 = true, flag3 = true;

        for (int i = 0; i < s.size(); i++)
        {
            if (is_vowel(s[i]))
            {
                flag1 = true;
            }

            if (i >= 2)
            {
                bool tmp1 = is_vowel(s[i - 2]);
                bool tmp2 = is_vowel(s[i - 1]);
                bool tmp3 = is_vowel(s[i]);

                if ((tmp1 && tmp2 && tmp3) || (!tmp1 && !tmp2 && !tmp3))
                {
                    flag2 = false;
                    break;
                }
            }

            if (i >= 1)
            {
                if (s[i] != 'e' && s[i] != 'o' && s[i - 1] == s[i])
                {
                    flag3 = false;
                    break;
                }
            }
        }

        if (flag1 & flag2 & flag3)
            printf("<%s> is acceptable.\n", s.c_str());
        else
            printf("<%s> is not acceptable.\n", s.c_str());
    }

    return 0;
}
