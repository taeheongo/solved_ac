/*
    submission : https://www.acmicpc.net/source/64696825
*/

#include <bits/stdc++.h>

using namespace std;

string s, tmp;
bool flag = true;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s;

    for (int i = 0; i < s.size();)
    {
        switch (s[i])
        {
        case 'p':
            if (i < s.size() - 1 && s[i + 1] == 'i')
                i += 2;
            else
                flag = false;

            break;
        case 'k':
            if (i < s.size() - 1 && s[i + 1] == 'a')
                i += 2;
            else
                flag = false;

            break;
        case 'c':
            if (i < s.size() - 2 && s[i + 1] == 'h' && s[i + 2] == 'u')
                i += 3;
            else
                flag = false;

            break;
        default:
            flag = false;
        }

        if (!flag)
            break;
    }

    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}