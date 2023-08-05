/*
    submission : https://www.acmicpc.net/problem/13244

    time : O(t * (m + n))

    tree 특징

        1. e = v - 1;
        2. cnt = 1;
*/

#include <bits/stdc++.h>

using namespace std;

int t, n, m, a, b;
vector<int> adj[1004];
int visited[1004];

void dfs(int here)
{
    visited[here] = 1;
    for (int there : adj[here])
    {
        if (!visited[there])
        {
            dfs(there);
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        int cnt = 0;
        cin >> n >> m;

        for (int i = 0; i < 1004; i++)
        {
            adj[i].clear();
        }
        fill(&visited[0], &visited[0] + 1004, 0);

        for (int i = 0; i < m; i++)
        {
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);
        }

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i])
            {
                dfs(i);
                cnt++;
            }
        }

        if (cnt == 1 && m == n - 1)
        {
            cout << "tree\n";
        }
        else
        {
            cout << "graph\n";
        }
    }

    return 0;
}