/*
    submission : https://www.acmicpc.net/source/65853324

    구현문제
        반복되는 부분작업이 많다 => iterative or recursive
        배열 회전 => 내장함수 rotate

    cin과 scanf를 같이 쓰지말 것.
*/

#include <bits/stdc++.h>

using namespace std;

int t, k, ret;
vector<string> vv(1004, "");
vector<int> v_dir(1004, 0);

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    for (int i = 0; i < t; i++)
        cin >> vv[i];

    cin >> k;

    int id, dir;
    while (k--)
    {
        cin >> id >> dir;
        fill(v_dir.begin(), v_dir.end(), 0);
        v_dir[--id] = dir;

        int d = dir * -1;
        for (int l = id; l > 0; l--)
        {
            if (vv[l - 1][2] == vv[l][6])
                break;

            v_dir[l - 1] = d;
            d *= -1;
        }

        d = dir * -1;
        for (int r = id + 1; r < t; r++)
        {
            if (vv[r - 1][2] == vv[r][6])
                break;

            v_dir[r] = d;
            d *= -1;
        }

        for (int i = 0; i < t; i++)
        {
            if (v_dir[i] == 0)
                continue;
            else if (v_dir[i] == 1)
                rotate(vv[i].begin(), vv[i].begin() + 7, vv[i].end());
            else if (v_dir[i] == -1)
                rotate(vv[i].begin(), vv[i].begin() + 1, vv[i].end());
        }
    }

    for (int i = 0; i < t; i++)
    {
        if (vv[i][0] == '1')
            ret++;
    }
    cout << ret << "\n";

    return 0;
}