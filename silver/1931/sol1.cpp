/*
    submission : https://www.acmicpc.net/source/64862772

    다음 회의가 시작가능한지는 결국 끝 시간이 결정하므로 끝 시간으로 정렬 후
    정렬을 해서 선형적으로 만들고
    끝 시간과 시작 시간을 비교하면 된다. => 그리디

    주의 해야할 점
        1. 문제에서 시작시간과 끝시간은 0 ~ 2^31-1 이라고 했으므로
        end_time을 -1로 지정해줘야 한다.

        2. 시작시간과 끝시간이 같은 회의도 존재하므로
        정렬할때 끝나는 시간 오름차순으로 정렬해주고,
        끝나는 시간이 같은 그룹끼리는 시작시간으로 오름차순을 해줘야 한다.
        그래야 시작시간과 끝시간이 같은 경우도 고려할 수 있다.

        .....   <- +1
            ... <- +1
             .. <- 무시
              . <- +1

        최대 회의 개수는 3

    time: O(NlogN)
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