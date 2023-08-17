/*
    submission : https://www.acmicpc.net/source/65194844

    time: O(NlogN)

    정렬 + 힙 으로 문제를 선형적으로 만든다 => 그리디

    최대값을 구하는 방법
        1. 최소힙에 최소값을 최대한 많이 빼주거나
        2. 최대힙에 가능한 많이 넣어서 최댓값을 구해주거나
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, a, b;
ll ret;
pair<int, int> arr_p[10004];
priority_queue<int, vector<int>, greater<int>> pq;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a >> b;
        arr_p[i] = {b, a};
    }

    sort(&arr_p[0], &arr_p[n]);

    for (int i = 0; i < n; i++)
    {
        pq.push(arr_p[i].second);
        if (pq.size() > arr_p[i].first)
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