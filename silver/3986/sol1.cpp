/*
    submission : https://www.acmicpc.net/source/61615040

    짝짓기, 폭발 => 스택
*/

#include <bits/stdc++.h>

using namespace std;

int n, ret;
string s;
stack<char> stk;

int main()
{
    cin >> n;

    char top;
    while (n--)
    {
        cin >> s;

        for (char c : s)
        {
            if (stk.size() && stk.top() == c)
            {
                stk.pop();
            }
            else
            {
                stk.push(c);
            }
        }

        if (stk.size() == 0)
        {
            ret++;
        }

        while (stk.size())
        {
            stk.pop();
        }
    }
    cout << ret << "\n";

    return 0;
}