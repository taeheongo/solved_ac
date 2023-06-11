/*
    submission : https://www.acmicpc.net/source/61972931

    int형 인접리스트로 풀이.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k, m, root;
vector<int> adj[50];

int dfs(int r)
{
    int ret = 0;
    for (auto e : adj[r])
    {
        if (e == m)
            continue;
        ret += dfs(e);
    }

    return ret == 0 ? 1 : ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> k;
        if (k == -1)
        {
            root = i;
            continue;
        }
        adj[k].push_back(i);
    }

    cin >> m;
    if (m == root)
        cout << 0 << "\n";
    else
        cout << dfs(root) << "\n";

    return 0;
}