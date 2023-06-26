/*
    submission : https://www.acmicpc.net/source/62536640

    10! = 약 360만 => 완전탐색 가능
    time <= 10!
*/

#include <bits/stdc++.h>

using namespace std;

int k;
char a[10];
bool check[10];
vector<string> ret;

void go(int idx, string s)
{
    if (idx == k + 1)
    {
        string tmp(s);
        ret.push_back(tmp);

        return;
    }

    for (int i = 0; i < 10; i++)
    {
        if (check[i])
            continue;

        if (idx >= 1)
        {
            if (a[idx - 1] == '>')
            {
                if (s[idx - 1] < '0' + i)
                    continue;
            }
            else
            {
                if (s[idx - 1] > '0' + i)
                    continue;
            }
        }

        s += '0' + i;
        check[i] = 1;
        go(idx + 1, s);
        check[i] = 0;
        s.erase(s.size() - 1);
    }
}

bool cmp(const string s1, const string s2)
{
    if (s1.size() == s2.size())
    {
        for (int i = 0; i < s1.size(); i++)
        {
            if (s1[i] > s2[i])
                return true;
            else if (s1[i] < s2[i])
                return false;
        }
    }

    return s1.size() > s2.size();
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;

    for (int i = 0; i < k; i++)
        cin >> a[i];

    string s = "";
    go(0, s);

    sort(ret.begin(), ret.end(), cmp);

    cout << ret[0] << "\n";
    cout << ret[ret.size() - 1] << "\n";

    return 0;
}
