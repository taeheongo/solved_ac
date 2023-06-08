/*
    submission : https://www.acmicpc.net/source/61854196

    구현 문제 + 함정 주의.

    각 줄은 최대 100글자라고 했으므로 최대 100자리수의 수가 나올 수 있다는 것.
    int를 사용할 수 없다. 당연히 atoi를 사용할 수 없고, string으로 처리해야함.
    공개 testcase에는 일부러 적은 자리수의 수만 보여줌.
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
        int i = 0;
        for (; i < num.size(); i++)
        {
            if (num[i] != '0')
                break;
        }
        num = num.substr(i);
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