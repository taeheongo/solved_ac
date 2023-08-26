/*
    submission : https://www.acmicpc.net/source/65621380

    time: T(n C n/2)
        => T(n C n/2)는 nCn/2를 구하는데 걸린 시간.

    nCk (k = n/2)를 구하고
    각각의 경우의 수에 대하여 min(두 팀의 합의 차)을 구하는 문제.
    n의 최대값이 20.
    20 C 10
    2^20이 = 10^6니까 그보다 훨씬 작은 값일 것이고, 해볼만하다.
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n, ret = INF;
int a[20][20];
vector<int> v1, v2;

void comb(int idx)
{
    if (v1.size() == n / 2)
    {
        int tmp1 = 0, tmp2 = 0;
        for (int i = 0; i < n / 2; i++)
        {
            v2.erase(find(v2.begin(), v2.end(), v1[i]));
            for (int j = i + 1; j < n / 2; j++)
            {
                tmp1 += a[v1[i]][v1[j]] + a[v1[j]][v1[i]];
            }
        }
        for (int i = 0; i < n / 2; i++)
        {
            for (int j = i + 1; j < n / 2; j++)
            {
                tmp2 += a[v2[i]][v2[j]] + a[v2[j]][v2[i]];
            }
        }

        int gap = abs(tmp1 - tmp2);
        ret = min(ret, gap);

        v2.clear();
        for (int i = 0; i < n; i++)
            v2.push_back(i);

        return;
    }

    for (int i = idx; i < n; i++)
    {
        v1.push_back(i);
        comb(i + 1);
        v1.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < n; i++)
        v2.push_back(i);

    comb(0);

    cout << ret << "\n";

    return 0;
}