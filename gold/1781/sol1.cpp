/*
    submission : https://www.acmicpc.net/source/65369341

    time: O(NlogN)
*/

#include <bits/stdc++.h>

using namespace std;

int n, ret;
pair<int, int> h[200000];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        h[i] = {a, b};
    }

    sort(h, h + n);

    for (int i = 0; i < n; i++)
    {
        pq.push(h[i].second);
        if (pq.size() > h[i].first)
        {
            pq.pop();
        }
    }

    while (pq.size())
    {
        ret += pq.top();
        pq.pop();
    }

    cout << ret << "\n";

    return 0;
}