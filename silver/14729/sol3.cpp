/*
    submission : https://www.acmicpc.net/source/64953047

    time: O(N)
        (N*log8) + log7 + log6 +... + log1 = N

    힙을 사용한 풀이2
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 7;
priority_queue<double, vector<double>> pq;
double ret[7];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    double num;
    while (n--)
    {
        cin >> num;
        pq.push(num);
        if (pq.size() > 7)
        {
            pq.pop();
        }
    }

    int idx = 0;

    while (pq.size())
    {
        ret[idx++] = pq.top();
        pq.pop();
    }

    reverse(&ret[0], &ret[7]);

    cout.precision(3);
    cout << fixed;

    for (int i = 0; i < 7; i++)
    {
        cout << ret[i] << "\n";
    }

    return 0;
}
