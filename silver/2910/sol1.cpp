/*
    submission : https://www.acmicpc.net/source/61837437

    커스텀 정렬 + 맵

    time: O(nlogn)
*/

#include <bits/stdc++.h>

using namespace std;

int n, c;
map<int, pair<int, int>> mp;
vector<int> ret;

bool cmp(int a, int b)
{
    if (mp[a].first == mp[b].first)
        return mp[a].second < mp[b].second;

    return mp[a].first > mp[b].first;
}

int main()
{
    cin >> n >> c;

    int num;
    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (mp.find(num) == mp.end())
            mp[num] = {1, i};
        else
            mp[num].first++;
    }

    for (auto e : mp)
    {
        ret.push_back(e.first);
    }

    sort(ret.begin(), ret.end(), cmp);

    for (auto e : ret)
    {
        for (int i = 0; i < mp[e].first; i++)
        {
            cout << e << " ";
        }
    }

    return 0;
}