/*
    submission : https://www.acmicpc.net/source/65888091

    cnt배열을 떠올릴 수 있지만 배열의 사이즈는 백만(10^6)이 최대.

    sort를 통해서 선형적으로 바꿔주고, idx를 따져가며 겹치는 부분 체크 => greedy

    time: O(NlogN)  => 약 10^5
        NlogN + N
*/
#include <bits/stdc++.h>

using namespace std;

int n, l, ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> l;
    vector<pair<int, int>> v_p(n);

    int s, e;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> e;
        s--;
        e--;
        v_p[i] = {s, e};
    }

    sort(v_p.begin(), v_p.end());

    int idx = 0;
    for (auto p : v_p)
    {
        if (idx <= p.first)
            idx = p.first;
        else if (idx >= p.second)
            continue;

        int k = (p.second - idx) / l;

        if ((p.second - idx) % l)
            k++;

        ret += k;
        idx += k * l;
    }

    cout << ret << "\n";

    return 0;
}