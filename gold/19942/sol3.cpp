/*
    submission : https://www.acmicpc.net/source/62682270

    조합을 굳이 비트연산으로만 구할 필요 없음.
    시간복잡도는 같음.
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n, ret = INF;
int mp, mf, ms, mv;
struct A
{
    int p, f, s, v, cost;
} a[16];
vector<int> v;
vector<vector<int>> vv;
map<int, vector<vector<int>>> ret_v;

void comb(int n, int r, int start)
{
    if (n - start < r - v.size())
        return;

    if (v.size() == r)
    {
        vector<int> copy_v(v);
        vv.push_back(copy_v);
        return;
    }

    for (int i = start; i < n; i++)
    {
        v.push_back(i);
        comb(n, r, i + 1);
        v.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    cin >> mp >> mf >> ms >> mv;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i].p >> a[i].f >> a[i].s >> a[i].v >> a[i].cost;
    }

    for (int r = 0; r <= n; r++)
    {
        comb(n, r, 0);
    }

    for (auto &e : vv)
    {
        A tmp = {0, 0, 0, 0, 0};
        vector<int> idx_v;
        for (int i : e)
        {
            tmp.f += a[i].f;
            tmp.p += a[i].p;
            tmp.s += a[i].s;
            tmp.v += a[i].v;
            tmp.cost += a[i].cost;

            idx_v.push_back(i + 1);
        }
        if (tmp.f < mf || tmp.p < mp || tmp.s < ms || tmp.v < mv || tmp.cost > ret)
            continue;

        ret = tmp.cost;
        ret_v[ret].push_back(idx_v);
    }

    if (ret != INF)
    {
        cout << ret << "\n";
        sort(ret_v[ret].begin(), ret_v[ret].end());
        for (int idx : ret_v[ret][0])
        {
            cout << idx << " ";
        }
        cout << "\n";
    }
    else
    {
        cout << -1 << "\n";
    }

    return 0;
}