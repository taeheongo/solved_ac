/*
    submission : https://www.acmicpc.net/source/61973575

    solution 0 구현 최적화.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct tree_node
{
    vector<tree_node *> adj;
} tree_node;

int n, k, m, root;
tree_node tn[50];
int a[50];

int dfs(tree_node *node)
{
    int ret = 0;
    for (auto e : node->adj)
    {
        if (e == &tn[m])
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
        cin >> a[i];
        if (a[i] == -1)
        {
            root = i; // root노드 지정.
            continue;
        }

        tn[a[i]].adj.push_back(&tn[i]);
    }

    cin >> m;

    if (m == root) // 꼭 root노드로 해야함. 0으로 하면 안됨.
        cout << 0 << "\n";
    else
        cout << dfs(&tn[root]) << "\n";

    return 0;
}
