/*
    submission : https://www.acmicpc.net/source/64947702

    time : O(N+K + NlogN + KlogK + K*logN)
    입력받는 부분을 빼고 보면.
    정렬에서 NlogN + KlogK 만큼 소요되는데

    반복문에서 최대 N + K + KlogN만큼 소요됨.

    35 30
    35 5
    50 20

    70

    1. 문제에서 일단 하나의 가방에는 하나의 보석만 들어간다고 했다. 70의 무게를 감당할 수 있는 가방에 35짜리 2개를 넣을 수 없다.

    2. 무게와 가격은 무관. 무게가 가볍다고 가격도 가벼운건 아니다.
        => 무게가 가벼운 것부터 넣는게 능사가 아니라는 것. => 가방이 감당가능한 무게중에서 제일 비싼 걸 넣어야 한다.

        각 가방에 넣을 수 있는 보석 중에 가장 큰 보석을 넣는다고 하면.
        최대 n^k만큼 걸린다.

        그런데 가방을 오름차순으로 정렬하면 이전 가방에서 넣을 수 있었던 건 이후의 가방에서도 넣을 수 있으므로
        문제를 선형적으로 만들 수 있다.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, k;
ll ret;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;
    vector<pair<int, int>> v(n);
    vector<int> vv(k);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    for (int i = 0; i < k; i++)
    {
        cin >> vv[i];
    }

    sort(v.begin(), v.end());
    sort(vv.begin(), vv.end());

    vector<int> heap;
    int j = 0;
    for (int i = 0; i < k; i++)
    {
        while (j < n && v[j].first <= vv[i])
        {
            heap.push_back(v[j].second);
            push_heap(heap.begin(), heap.end());
            j++;
        }

        if (heap.size())
        {
            ret += heap[0];
            pop_heap(heap.begin(), heap.end());
            heap.pop_back();
        }
    }

    cout << ret << "\n";

    return 0;
}