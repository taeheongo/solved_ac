/*
    submission : https://www.acmicpc.net/submit/17471/64135815

    time: O(n * 2^n)

    조합을 꼭 bit operation으로 구할필요는 없다.
    주석으로 되어있는 부분 주의.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 11;
const int INF = 987654321;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};

int n, m, u, ret = INF;
int a[max_n], color[max_n], visited[max_n];
vector<int> adj_list[max_n];
vector<int> v1, v0;

pair<int, int> dfs(int here, int c)
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

void solve()
{
    fill(&visited[0], &visited[0] + max_n, 0);

    pair<int, int> p0 = dfs(v0[0], 0);
    pair<int, int> p1 = dfs(v1[0], 1);

    if (p0.second + p1.second != n)
        return;

    ret = min(ret, abs(p0.first - p1.first));
}

void comb(int n, int r, int start)
{
    if (v1.size() == r)
    {
        for (int i = start; i <= n; i++)
        {
            v0.push_back(i);
        }

        solve();

        for (int i = start; i <= n; i++)
        {
            v0.pop_back();
        }

        return;
    }

    for (int i = start; i <= n; i++)
    {
        v1.push_back(i);
        color[i] = 1;
        comb(n, r, i + 1);
        v1.pop_back();
        color[i] = 0;
        v0.push_back(i);
    }

    // 하나의 comb가 끝나면 v1은 롤백되지만 v0는 아니다.
    // 그래서 수동으로 롤백해줘야댐.
    for (int i = start; i <= n; i++)
    {
        v0.pop_back();
    }
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

    for (int r = 1; r < n; r++)
    {
        v0.clear();
        comb(n, r, 1);
    }

    if (ret == INF)
        cout << -1 << "\n";
    else
        cout << ret << "\n";

    return 0;
}