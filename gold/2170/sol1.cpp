/*
    submission : https://www.acmicpc.net/source/64980686

    순회하면서 빠지는 곳 없이 탐색가능 => 라인 스위핑

    time : O(NlogN)
*/

#include <bits/stdc++.h>

using namespace std;

int n, l, r, ret;
pair<int, int> p[1000000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> p[i].first >> p[i].second;
    }

    sort(&p[0], &p[n]);

    tie(l, r) = p[0];
    for (int i = 1; i < n; i++)
    {
        if (r < p[i].first)
        {
            ret += r - l;
            tie(l, r) = p[i];
        }
        else if (r <= p[i].second)
        {
            r = p[i].second;
        }
    }

    ret += r - l;

    cout << ret << "\n";

    return 0;
}