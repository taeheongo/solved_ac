/*
    submission : https://www.acmicpc.net/source/62679406

    solution 1과 논리는 같음.
    구현 부분에서 차이가 있는데
    1. 하나의 row에 p,f,s,v, cost 이렇게 5개의 값이 있으므로 구조체를 쓰는 것이 더 좋아보임.
    2. 정답이 여러 개면 문제에서 사전순으로 첫 번째 값을 출력하라고 했는데
        solution1에서는
            vector<vector<int>> ret_v[2004];
        을 사용했음.
        0 <= mp, mf, ms, mv <= 500

        그런데 2000정도 되면 그냥
            map<int, vector<vector<int>>> ret_v;
        map을 쓰는 것이 좋아보임.
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

map<int, vector<vector<int>>> ret_v;

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

    for (int i = 0; i < (1 << n); i++)
    {
        A tmp = {0, 0, 0, 0, 0};
        vector<int> idx_v;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                tmp.f += a[j].f;
                tmp.p += a[j].p;
                tmp.s += a[j].s;
                tmp.v += a[j].v;
                tmp.cost += a[j].cost;

                idx_v.push_back(j + 1);
            }
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