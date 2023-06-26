/*
    submission : https://www.acmicpc.net/source/62537287

    최대 약 10! 정도가 나올 수 있기 때문에
    정렬을 사용하지 않고 min_num과 max_num을 사용해서 구하기.
*/

#include <bits/stdc++.h>

using namespace std;

int k;
char a[10];
bool check[10];
string max_num = "0000000000", min_num = "9999999999";

bool cmp(const string &s1, const string &s2)
{
    for (int i = 0; i < k + 1; i++)
    {
        if (s1[i] > s2[i])
            return true;
        else if (s1[i] < s2[i])
            return false;
    }
}

void go(int idx, string s)
{
    if (idx == k + 1)
    {
        if (!cmp(max_num, s))
            max_num = s;

        if (cmp(min_num, s))
            min_num = s;

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

    cout << max_num << "\n";
    cout << min_num << "\n";

    return 0;
}
