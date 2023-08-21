/*
    submission : https://www.acmicpc.net/source/65378081


    time : O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int n, a, b, cur_time;
pair<int, int> p[100];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        p[i] = {a, b};
    }

    sort(p, p + n);

    cur_time = p[0].first + p[0].second;
    for (int i = 1; i < n; i++)
    {
        cur_time = max(cur_time, p[i].first);
        cur_time += p[i].second;
    }

    cout << cur_time << "\n";

    return 0;
}