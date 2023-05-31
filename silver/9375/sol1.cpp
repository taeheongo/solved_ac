/*
    submission : https://www.acmicpc.net/source/61546797

*/

#include <bits/stdc++.h>

using namespace std;

int m, n;
map<string, int> mp;
string type, name;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> m;

    while (m--)
    {
        cin >> n;
        while (n--)
        {
            cin >> name >> type;
            mp[type]++;
        }

        int ret = 1;
        for (auto e : mp)
        {
            ret *= e.second + 1;
        }
        ret -= 1;

        cout << ret << "\n";
        mp.clear();
    }

    return 0;
}