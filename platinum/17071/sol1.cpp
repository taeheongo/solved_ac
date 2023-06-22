/*
    submission : https://www.acmicpc.net/status?user_id=sadness1764&problem_id=17071&from_mine=1

    time: O(3^N)

    1 + 3 + 9 + ... 3^500000
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
const int M = 500000;
bool flag = true;
bool visited[M + 4];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    queue<int> q;
    queue<int> q2;

    q.push(n);

    int d = 1;

    while (q.size())
    {
        int m = q.front();
        q.pop();

        if (m == k)
        {
            cout << d - 1 << "\n";
            flag = false;
            break;
        }

        for (int next_m : {m - 1, m + 1, m * 2})
        {
            if (next_m < 0 || next_m > M)
                continue;

            if (!visited[next_m])
            {
                visited[next_m] = 1;
                q2.push(next_m);
            }
        }

        if (q.empty())
        {
            while (q2.size())
            {
                q.push(q2.front());
                visited[q2.front()] = 0;
                q2.pop();
            }

            k += d;
            d++;
        }

        if (k > M)
            break;
    }

    if (flag)
        cout << -1 << "\n";

    return 0;
}