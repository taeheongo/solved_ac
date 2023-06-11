/*
    submission : https://www.acmicpc.net/source/61959472

    트리의 리프 노드 개수를 구하는 문제.

    이 문제를 풀 때 내가 했던 실수들:

    1. 문제에서 이진트리라고 한 적이 없음.
        (예제에서 이진트리만 보여줘서 당연히 이진트리로 생각했었음.)
    2. root 노드가 0번째 노드일거라고 생각한 것.
        (이것도 문제에서 루트노드가 0번째 노드라고 언급한적이 없음.)
        부모노드가 -1인 노드를 루트노드로 지정해줘야함.
    3. 트리노드 인접리스트를 만들어도되지만, 그냥 int형 인접리스트만 만들어도됨.
    4. 인접리스트에서 해당 노드를 직접 제거하지 않아도 됨. 트리이기 때문에 단방향이고, 해당노드에게 가는 간선은 하나뿐임. 그래서 그냥 패스하면 됨.
*/

#include <bits/stdc++.h>

using namespace std;

typedef struct tree_node
{
    vector<tree_node *> adj;
} tree_node;

int n, num, ret, root;
tree_node tn[50];
int a[50];

void dfs(tree_node *node)
{
    if (node == NULL)
    {
        return;
    }

    if ((node->adj).size() == 0)
    {
        ret++;
    }

    for (auto e : node->adj)
    {
        dfs(e);
    }
}

void solve()
{
    if (a[num] == -1)
    {
        return;
    }

    auto &adj = tn[a[num]].adj;

    int i = 0;
    for (; i < adj.size(); i++)
    {
        if (adj[i] == &tn[num])
        {
            break;
        }
    }

    adj.erase(adj.begin() + i); // 굳이 제거할 필요없음.

    dfs(&tn[root]);
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
            root = i;
            continue;
        }

        tn[a[i]].adj.push_back(&tn[i]);
    }

    cin >> num;

    solve();

    cout << ret << "\n";

    return 0;
}