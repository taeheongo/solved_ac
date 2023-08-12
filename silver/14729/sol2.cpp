/*
    submission : https://www.acmicpc.net/source/64950974

    time: (log1 + log2 + ... + logN)
            <= NlogN
*/
#include <bits/stdc++.h>

using namespace std;

int n, cnt = 7;
priority_queue<double, vector<double>, greater<double>> pq;

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
    }

    cout.precision(3);
    cout << fixed;
    while (cnt--)
    {
        cout << pq.top() << "\n";
        pq.pop();
    }

    return 0;
}
