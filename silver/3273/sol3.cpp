/*
    submission : https://www.acmicpc.net/source/64983439

    time: O(NlogN)

    정렬 부분 빼면 O(N)임.
*/

#include <bits/stdc++.h>

using namespace std;

int n, l, r, x, ret;
int a[100000];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> x;

    sort(&a[0], &a[n]);

    r = n - 1;
    while (l < r)
    {
        if (a[l] + a[r] == x)
        {
            cout << a[l] << ", " << a[r] << "\n";
            ret++;
            r--;
        }
        else if (a[l] + a[r] < x)
        {
            l++;
        }
        else
        {
            r--;
        }
    }

    cout << ret << "\n";

    return 0;
}