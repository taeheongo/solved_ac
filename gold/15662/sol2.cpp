/*
    submission : https://www.acmicpc.net/source/65878274

    sol 1과 논리는 같음.
    v_dir을 쓰지 않고 dir 변수 하나로 할 수 있다.
    회전하는 톱니바퀴들은 연속적이기 때문.
*/

#include <bits/stdc++.h>

using namespace std;

int t, k, ret;
vector<string> vv(1004, "");

void rotate_2d(int i, int dir)
{
    if (dir == 1)
        rotate(vv[i].begin(), vv[i].begin() + 7, vv[i].end());
    else
        rotate(vv[i].begin(), vv[i].begin() + 1, vv[i].end());
}

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
        id--;
        int l = id;
        for (; l > 0; l--)
        {
            if (vv[l - 1][2] == vv[l][6])
                break;
        }

        int r = id + 1;
        for (; r < t; r++)
        {
            if (vv[r - 1][2] == vv[r][6])
                break;
        }
        r--;

        int d = dir;
        for (int i = id; i >= l; i--)
        {
            rotate_2d(i, d);
            d *= -1;
        }

        d = -1 * dir;
        for (int i = id + 1; i <= r; i++)
        {
            rotate_2d(i, d);
            d *= -1;
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