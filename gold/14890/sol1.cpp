/*
    submission : https://www.acmicpc.net/source/64235315

    time : O(N^2)

    cnt를 활용해서 순회를 통해 확인하지 않아도 되는 방법.
*/

#include <bits/stdc++.h>

using namespace std;

const int max_n = 100;

int n, l, ret;
int a[max_n][max_n], b[max_n][max_n];

void solve(int a[max_n][max_n])
{
    for (int i = 0; i < n; i++)
    {
        int cnt = 1;
        int j = 0;
        for (; j < n - 1; j++)
        {
            if (a[i][j] == a[i][j + 1])
            {
                cnt++;
            }
            else if ((a[i][j] - 1 == a[i][j + 1]) && cnt >= 0)
            {
                cnt = -l + 1;
            }
            else if ((a[i][j] + 1 == a[i][j + 1]) && cnt >= l)
            {
                cnt = 1;
            }
            else
            {
                break;
            }
        }

        if (j == n - 1 && cnt >= 0)
            ret++;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> a[i][j];
            b[j][i] = a[i][j];
        }
    }

    solve(a);
    solve(b);

    cout << ret << "\n";

    return 0;
}

/*
    2  2  3  3  2  2  1  1
cnt 1  2  1  2 -1 -1  0

*/