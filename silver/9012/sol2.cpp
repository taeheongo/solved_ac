/*
    submission : https://www.acmicpc.net/source/61911773

    좀 더 까끔한 구현.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;

bool check(string s)
{
    stack<char> stk;
    for (char c : s)
    {
        if (c == '(')
            stk.push('(');
        else
        {
            if (stk.empty())
                return false;
            else
                stk.pop();
        }
    }

    return stk.empty();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    while (n--)
    {
        cin >> s;

        if (check(s))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}