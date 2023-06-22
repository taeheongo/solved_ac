/*
    submission : https://www.acmicpc.net/source/62372786

    time: O(N)
*/

#include <bits/stdc++.h>
using namespace std;

const int M = 500000;

int n, k, depth = 1;
bool flag = false;
bool visited[2][M + 4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    if (n == k)
    {
        cout << 0 << "\n";
        return 0;
    }

    queue<int> q;
    visited[0][n] = 1;
    q.push(n);

    while (q.size())
    {
        k += depth;
        if (k > M)
            break;

        int cur = depth % 2;
        if (visited[cur][k])
        {
            flag = true;
            break;
        }

        int q_size = q.size();
        while (q_size--)
        {
            int m = q.front();
            q.pop();

            for (int next_m : {m - 1, m + 1, m * 2})
            {
                if (next_m < 0 || next_m > M)
                    continue;

                if (next_m == k)
                {
                    flag = true;
                    break;
                }

                if (!visited[cur][next_m])
                {
                    visited[cur][next_m] = 1;
                    q.push(next_m);
                }
            }

            if (flag)
                break;
        }
        if (flag)
            break;

        depth++;
    }

    if (flag)
        cout << depth << "\n";
    else
        cout << -1 << "\n";

    return 0;
}