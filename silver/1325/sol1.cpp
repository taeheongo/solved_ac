/*
    submission : https://www.acmicpc.net/source/61977463

    1. 문제를 읽고 양방향일 수 있다는 것을 파악하고 그래프로 생각.
    2. 각 노드마다 자식의 수를 구하고 정렬을 해서 그 최대값인 노드를 출력.

    time: O(N * (N + M))
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, a, b;
vector<int> adj[10004];
bool visited[10004];
vector<pair<int, int>> ret;

int dfs(int here)
{
    visited[here] = true;

    int ret = 0;
    for (int there : adj[here])
    {
        if (visited[there] == 0)
            ret += dfs(there);
    }

    return ret + 1;
}

bool cmp(const pair<int, int> &p1, const pair<int, int> &p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second > p2.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        cin >> a >> b;

        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
    {
        ret.push_back({i, dfs(i)});
        memset(visited, 0, sizeof(visited));
    }

    sort(ret.begin(), ret.end(), cmp);

    for (int i = 0; i < (int)ret.size(); i++)
    {
        if (ret[i].second != ret[0].second)
            break;

        cout << ret[i].first << " ";
    }

    return 0;
}