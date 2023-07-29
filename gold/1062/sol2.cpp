/*
    submission : https://www.acmicpc.net/source/64240375

    time: (26 C k) * n * (5 ~ 18)
    (단, (1 <= n <= 50))

    26Ck만 계산하기 위해서 bit opreration을 사용하지 않음.
    그런데 bit operation을 사용하지 않다보니 자잘자잘한 for문이 들어가서
    성능은 별로 좋지 않음.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, x, ret;
string s_arr[50];
char b[5] = {'a', 'n', 't', 'i', 'c'};

vector<int> v;
vector<vector<int>> vv;

void comb(int r, int start)
{
    if (v.size() == r)
    {
        vector<int> copy_v(26, 0);
        for (int i = 0; i < 5; i++)
            copy_v[b[i] - 'a'] = 1;

        for (int c : v)
            copy_v[c] = 1;

        vv.push_back(copy_v);
        return;
    }

    for (int i = start; i < 26; i++)
    {
        int n = i + 'a';
        if (n == 'a' || n == 'n' || n == 't' || n == 'i' || n == 'c')
            continue;

        v.push_back(i);
        comb(r, i + 1);
        v.pop_back();
    }
}

void solve()
{
    if (k < 5)
        return;

    comb(k - 5, 0);

    for (auto e : vv)
    {
        int cnt = 0;
        for (int i = 0; i < n; i++)
        {
            int j = 0;
            for (; j < s_arr[i].size(); j++)
            {
                if (e[s_arr[i][j] - 'a'] == 0)
                    break;
            }

            if (j == s_arr[i].size())
            {
                cnt++;
            }
        }

        ret = max(ret, cnt);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        cin >> s_arr[i];
    }

    solve();

    cout << ret << "\n";

    return 0;
}