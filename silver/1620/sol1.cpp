/*
    submission : https://www.acmicpc.net/source/61544160

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    이거 안쓰면 시간초과 나옴.
    무조건 먼저 쓰고 시작.
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, int> mp;
string arr[100004];
string s;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        cin >> s;
        arr[i] = s;
        mp[s] = i;
    }

    int j = 0;
    for (int i = 0; i < m; i++)
    {
        cin >> s;
        if ((j = atoi(s.c_str())))
        {
            cout << arr[j] << "\n";
        }
        else
        {
            cout << mp[s] << "\n";
        }
    }

    return 0;
}