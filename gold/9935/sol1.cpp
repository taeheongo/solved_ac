/*
    submission : https://www.acmicpc.net/source/65369697

    time: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

string s, p, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> s >> p;

    for (int i = 0; i < s.size(); i++)
    {
        ret += s[i];
        if (ret.size() >= p.size() && ret.substr(ret.size() - p.size(), p.size()) == p)
        {
            ret.erase(ret.size() - p.size(), p.size());
        }
    }

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