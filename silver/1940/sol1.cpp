/*
    submission : https://www.acmicpc.net/source/61594216

    조합을 이용한 풀이
    time: O(N^2)
*/

#include <bits/stdc++.h>

using namespace std;

int n, m, ret;
int a[150000];

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == m)
                ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}