/*
    submission : https://www.acmicpc.net/source/65370133

    time: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

string ret, s, p;
stack<char> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> p;

    for (int i = 0; i < s.size(); i++)
    {
        stk.push(s[i]);

        if (stk.size() >= p.size())
        {
            int size = p.size();
            string tmp = "";
            while (size--)
            {
                tmp += stk.top();
                stk.pop();
            }

            reverse(tmp.begin(), tmp.end());

            if (tmp != p)
            {
                for (char c : tmp)
                {
                    stk.push(c);
                }
            }
        }
    }

    while (stk.size())
    {
        ret += stk.top();
        stk.pop();
    }

    reverse(ret.begin(), ret.end());

    if (ret.size())
    {
        cout << ret << "\n";
    }
    else
    {
        cout << "FRULA\n";
    }

    return 0;
}