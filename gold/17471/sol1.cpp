/*
    submission : https://www.acmicpc.net/source/62769208

    time: O(n * 2^n) (2 <= n <= 10)
        => 조합의 개수 2^n 각각의 개수에 대해서 순회 n

    n개의 원소를 2개의 connected component로 나누어야 하고,
    그 두 connected component의 인구수의 차의 최소를 구하는 문제

    2개의 connected component로 나누는 부분.
    조합 : nC2 + nC3 + ... + nC5
    for (int i = 1; i < (1 << n) - 1; i++)
    {
        ...
    }

    어떤 수들을 뽑았는지 확인하는 부분
    for (int j = 0; j < n; j++)
    {
        if (i & (1 << j)){
            ...
        }
    }

    그리고 dfs로 connected component의 개수와 인구수의 합을 구할 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 11;
const int INF = 987654321;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, u, idx0, idx1, ret = INF;
int a[max_n];
bool visited[max_n];
bool color[max_n];
vector<int> adj_list[max_n];

pair<int, int> dfs(int here, bool c)
{
    visited[here] = 1;
    pair<int, int> ret = {a[here], 1};
    for (int there : adj_list[here])
    {
        if (visited[there] || color[there] != c)
            continue;

        pair<int, int> tmp = dfs(there, c);
        ret.first += tmp.first;
        ret.second += tmp.second;
    }

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> m;
        while (m--)
        {
            cin >> u;
            adj_list[i].push_back(u);
            adj_list[u].push_back(i);
        }
    }

    for (int i = 1; i < (1 << n) - 1; i++)
    {
        fill(&visited[0], &visited[0] + max_n, 0);
        fill(&color[0], &color[0] + max_n, 0);

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                color[j + 1] = 1;
                idx1 = j + 1;
            }
            else
            {
                idx0 = j + 1;
            }
        }

        pair<int, int> p0 = dfs(idx0, 0);
        pair<int, int> p1 = dfs(idx1, 1);

        if (p0.second + p1.second != n)
            continue;

        ret = min(ret, abs(p0.first - p1.first));
    }

    if (ret == INF)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}