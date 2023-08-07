/*
    submission : https://www.acmicpc.net/source/64696080
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

    for (int i = 0; i < s.size(); i++)
    {
        tmp += s[i];

        if (tmp.size() == 2)
        {
            if (tmp == "pi" || tmp == "ka")
            {
                tmp = "";
            }
            else
            {
                if (i < s.size() && s[i + 1] == 'c')
                {
                    flag = false;
                    break;
                }
            }
        }
        else if (tmp.size() == 3)
        {
            if (tmp != "chu")
            {
                flag = false;
                break;
            }
            tmp = "";
        }
    }

    if (tmp.size() >= 1 || !flag)
    {
        cout << "NO\n";
    }
    else
    {
        cout << "YES\n";
    }

    return 0;
}