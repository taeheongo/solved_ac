/*
    submission : https://www.acmicpc.net/source/62331528

    time: O(N)

    12851문제에서 역추적만 추가된문제
    문제에서 하나의 케이스만 출력하면 된다고 했으므로 pre를 벡터배열로 할 필요는 업다.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int visited[200004];
int pre[200004];

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    queue<int> q;
    q.push(n);
    visited[n] = 1;

    if (n == k)
    {
        cout << 0 << "\n";
        cout << k << "\n";

        return 0;
    }

    while (q.size())
    {
        int m = q.front();
        q.pop();

        if (visited[k])
            break;

        for (int next_m : {m - 1, m + 1, m * 2})
        {
            if (next_m < 0 || next_m > 200000)
                continue;

            if (!visited[next_m])
            {
                visited[next_m] = visited[m] + 1;
                q.push(next_m);
                pre[next_m] = m;
            }
        }
    }

    cout << visited[k] - 1 << "\n";

    vector<int> v;
    for (int i = k; i != n; i = pre[i])
    {
        v.push_back(i);
    }
    v.push_back(n);

    reverse(v.begin(), v.end());
    for (int e : v)
    {
        cout << e << " ";
    }

    return 0;
}