/*
    submission : https://www.acmicpc.net/source/62324885

    solution 1에서의 문제점들을 개선한 코드
    time: O(N)

    이번에는 최단거리로 가는 개수를 구하기 위한 cnt 배열을 사용했는데
    예를 들어, n = 5 k =17 이라고 하면

    2 -> 17
    2를 거쳐서 최종적으로 k인 17에 도달했고
    이 경우의 수(cnt[k]) = 2, visited[k] = 4 라고 하자.

    이 이후에 2로 3번만에 가는(visited[k] = 3)의 경우의 수는 더 나오지 않는다.
    그게 bfs이다. 최단거리를 다 탐색하면서 가기때문.

    그래서 딱 2가지 케이스만 고려해주면 된다.

    if (!visited[next_m]) // 한번도 방문하지 않았을 때
    {
        visited[next_m] = visited[m] + 1;
        q.push(next_m);
        cnt[next_m] += cnt[m];
    }
    else if (visited[next_m] == visited[m] + 1) // 같은 depth일 때
    {
        cnt[next_m] += cnt[m];
    }else{
        // 이 이후에는 더 큰 depth 이기 때문에 패스
        // (visited[next_m] < visited[m] + 1 인 케이스)
    }
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
// 문제에서 0 <= n, k <= 100000 라고 했으므로 조심.
int visited[200004];
int cnt[200004];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    // n == k가 같을 때는 이 문제에서는 이 부분이 없어도 통과되지만 항상 체크하는 습관을 들이는게 좋다.
    if (n == k)
    {
        cout << 0 << "\n";
        cout << 1 << "\n";

        return 0;
    }

    visited[n] = 1;
    cnt[n] = 1;

    queue<int> q;
    q.push(n);

    while (q.size())
    {
        int m = q.front();
        q.pop();

        for (int next_m : {m + 1, m - 1, m * 2})
        {
            // 문제에서 0 <= n, k <= 100000 라고 했으므로 조심.
            if (next_m < 0 || next_m > 200000)
                continue;

            if (!visited[next_m])
            {
                visited[next_m] = visited[m] + 1;
                q.push(next_m);
                cnt[next_m] += cnt[m];
            }
            else if (visited[next_m] == visited[m] + 1)
            {
                cnt[next_m] += cnt[m];
            }
        }
    }

    cout << visited[k] - 1 << "\n";
    cout << cnt[k] << "\n";

    return 0;
}