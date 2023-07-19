/*
    submission : https://www.acmicpc.net/source/63718001

    time    : O(n * 2^n + klogk) =O(n * 2^n)          (3<= n <= 15, 0<= k <= 2^n)
    최대 시간 : n * 2^n + n * 2^n
*/

#include <bits/stdc++.h>

using namespace std;

const int INF = 987654321;

int n, ret = INF;
vector<vector<int>> ret_v[8004];
int m[4];
int a[20][5];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < 4; i++)
    {
        cin >> m[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < (1 << n); i++)
    {
        int tmp[5] = {0, 0, 0, 0, 0};
        vector<int> idx_v;

        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                for (int k = 0; k < 5; k++)
                    tmp[k] += a[j][k];
                idx_v.push_back(j + 1);
            }
        }

        bool flag = true;
        for (int j = 0; j < 4; j++)
        {
            if (tmp[j] < m[j])
            {
                flag = false;
                break;
            }
        }
        if (!flag)
            continue;

        if (tmp[4] <= ret)
        {
            ret = tmp[4];
            ret_v[ret].push_back(idx_v);
        }
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