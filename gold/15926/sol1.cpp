/*
    submission : https://www.acmicpc.net/source/64720231
*/

#include <bits/stdc++.h>

using namespace std;

int n, cnt, ret;
string s;
stack<int> stk;
int d[200004];

int main()
{
    cin >> n >> s;

    for (int i = 0; i < n; i++)
    {
        if (s[i] == '(')
        {
            stk.push(i);
        }
        else if (stk.size())
        {
            d[i] = d[stk.top()] = 1;
            stk.pop();
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (d[i])
        {
            cnt++;
            ret = max(ret, cnt);
        }
        else
        {
            cnt = 0;
        }
    }

    cout << ret << "\n";

    return 0;
}