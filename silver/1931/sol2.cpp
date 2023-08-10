/*
    submission : https://www.acmicpc.net/source/64862454

    정렬은 오름차순이 기본값이므로,
    {끝시간, 시작시간} 이런형태의 pair로 이루어진 vector를 만든다면
    커스텀 정렬을 할 필요가 없어진다.
*/
#include <bits/stdc++.h>

using namespace std;

int n, ret, s, e;
vector<pair<int, int>> v;

bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    if (p1.second == p2.second)
    {
        return p1.first < p2.first;
    }

    return p1.second < p2.second;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;
    while (n--)
    {
        cin >> s >> e;
        v.push_back({s, e});
    }

    sort(v.begin(), v.end(), cmp);

    int end_time = -1;
    for (auto e : v)
    {
        if (end_time > e.first)
            continue;

        ret++;
        end_time = e.second;
    }

    cout << ret << "\n";

    return 0;
}