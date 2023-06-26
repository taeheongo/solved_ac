/*
    submission : https://www.acmicpc.net/source/62539185

    inorder 순회보고 level화 시키기.

    time : O(2^k)
*/

#include <bits/stdc++.h>

using namespace std;

int k, last_idx;
int a[1100];
vector<vector<int>> vv;

void go(int start, int end, int depth)
{
    if (depth == k)
        return;

    int idx = (start + end) / 2;
    vv[depth].push_back(a[idx]);

    go(start, idx - 1, depth + 1);
    go(idx + 1, end, depth + 1);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k;
    last_idx = pow(2, k) - 2;
    for (int i = 0; i <= last_idx; i++)
        cin >> a[i];

    for (int i = 0; i < k; i++)
        vv.push_back(vector<int>());

    go(0, last_idx, 0);

    for (auto v : vv)
    {
        for (int i : v)
        {
            cout << i << " ";
        }
        cout << "\n";
    }

    return 0;
}