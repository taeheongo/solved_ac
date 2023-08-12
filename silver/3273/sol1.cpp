/*
    submission : https://www.acmicpc.net/source/64988714

    조합으로 찾으면

    10^5 C 2는 대략 10^10 정도니까 최대 10억번 정도 돌게된다.
    시간초과가 남.
*/

#include <bits/stdc++.h>

using namespace std;

int n, x, ret;
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

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (a[i] + a[j] == x)
                ret++;
        }
    }

    cout << ret << "\n";

    return 0;
}