/*
    submission : https://www.acmicpc.net/source/61854594

    같은 기능을 하는 helper 함수를 구현하는 방식이 달라서 함 해봄.
    전체적인 로직은 solution 1과 같음.
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
vector<string> ret;

void helper(string &num, vector<string> &ret)
{
    if (num != "")
    {
        while (num.size() && num.front() == '0')
        {
            num.erase(num.begin());
        }
        num = num == "" ? "0" : num;
        ret.push_back(num);
        num = "";
    }
}

bool cmp(const string &a, const string &b)
{
    if (a.size() == b.size())
    {
        return a < b;
    }

    return a.size() < b.size();
}

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> s;

        string num = "";
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                num += c;
                continue;
            }
            else
            {
                helper(num, ret);
            }
        }

        if (num != "")
        {
            helper(num, ret);
        }
    }

    sort(ret.begin(), ret.end(), cmp);

    for (string e : ret)
    {
        cout << e << "\n";
    }

    return 0;
}