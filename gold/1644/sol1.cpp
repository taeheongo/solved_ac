/*
    submission : https://www.acmicpc.net/source/65394009

    O(N * sqrt(N))

    에라토스테네스 체 + 2 pointer
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
int n, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    vector<bool> che(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        if (che[i] == 0)
            continue;

        for (int j = 2 * i; j <= n; j += i)
        {
            che[j] = 0;
        }
    }

    vector<int> v;
    for (int i = 2; i <= n; i++)
    {
        if (che[i] == 1)
        {
            v.push_back(i);
        }
    }

    int l = 0, r = 0;
    ll sum = 2;
    while (r < v.size() && l <= r)
    {
        if (sum > n)
        {
            sum -= v[l++];
        }
        else if (sum <= n)
        {
            if (sum == n)
            {
                ret++;
            }
            if (++r < v.size())
            {
                sum += v[r];
            }
        }
    }

    cout << ret << "\n";

    return 0;
}