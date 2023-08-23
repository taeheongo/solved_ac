/*
    submission : https://www.acmicpc.net/source/65527654

    Memory Paiging Optimal Algorithm
        => 정해진 공간에서 swap을 최소화(Page fault를 최소화)할 수 있는 알고리즘.
            FIFO, LRU, LFU, CLOCK 등이 있지만, 미래를 알고 있다면 OPR가 가장 효율적.

    OPR(Optimal Page Replacement) 알고리즘.
        가장 미래에 참조되는 페이지를 쫓아내는 방법.
        이론상 BEST지만, 실제로는 어떤 프로그램을 몇 번 쓸지 모르기 때문에 사용이 불가능하지만
        이 문제에서는 어떤 프로그램을 몇 번 쓰는지를 다 제공하기 때문에 사용가능.

    time : O(N * K)
*/

#include <bits/stdc++.h>
using namespace std;

int k, n, ret;
int a[104], visited[104];
vector<int> v;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> k >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    for (int i = 0; i < n; i++)
    {
        if (visited[a[i]])
            continue;

        if (v.size() == k)
        {
            int farthest_idx = 0;
            int v_idx = v.size() - 1;
            int farthest_num = v[v.size() - 1];

            for (int k = 0; k < v.size(); k++)
            {
                int j = i + 1;
                for (; j < n; j++)
                {
                    if (v[k] == a[j])
                        break;
                }

                if (farthest_idx <= j)
                {
                    farthest_idx = j;
                    v_idx = k;
                    farthest_num = v[k];
                }
            }

            v.erase(v.begin() + v_idx);
            ret++;
            visited[farthest_num] = 0;
        }

        v.push_back(a[i]);
        visited[a[i]] = 1;
    }

    cout << ret << "\n";

    return 0;
}