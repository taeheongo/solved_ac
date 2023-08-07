/*
    submission : https://www.acmicpc.net/source/64697937

    substr 사용.
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
        tmp = s.substr(i, 2);

        if (i < s.size() - 1)
        {
            if (tmp == "pi" || tmp == "ka")
            {
                i += 2;
                continue;
            }
            if (i < s.size() - 2)
            {
                tmp = s.substr(i, 3);
                if (tmp == "chu")
                {
                    i += 3;
                    continue;
                }
            }
        }

        flag = false;
        break;
    }

    if (flag)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}