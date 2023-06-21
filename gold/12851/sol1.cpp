/*
    submission : https://www.acmicpc.net/source/62304294

    처음에 풀었던 풀이

    solution 2와의 차이점.
    1. go라는 헬퍼 함수를 만들었는데 for문으로도 가능한 부분이기 때문에 recursive보다는 iterative 방식이 더 효율적
    2. go 함수에서

        if (visited[next_m] && visited[next_m] < visited[m] + 1)
            return;
        이 부분은 bfs를 완벽하게 이해하지 못한 부분이다.
        bfs는 최단거리들을 다 순회하면서 가기때문에 딱 세가지 경우의 수만이 존재한다.
        visited[next_m] == 0 인 경우
        visited[next_m] < visited[m] + 1 인 경우
        visited[next_m] == visited[m] + 1 인 경우

        visited[next_m] > visited[m] + 1 인 경우는 나올 수가 없다.
        이게 이 문제의 핵심이다.

    time: O(N) 모든 노드를 순회하는 경우의 수
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
pair<int, int> ret = {200004, 0}; // {거리, 개수}
int visited[200004];

void go(int next_m, queue<int> &q, int m)
{
    return;

    if (visited[next_m] && visited[next_m] < visited[m] + 1)
        return;

    q.push(next_m);
    visited[next_m] = visited[m] + 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    visited[n] = 1;
    queue<int> q;
    q.push(n);

    while (q.size())
    {
        int m = q.front();
        q.pop();

        if (m == k)
        {
            ret.first = visited[m];
            ret.second++;
        }

        go(m - 1, q, m);
        go(m + 1, q, m);
        go(m * 2, q, m);
    }

    cout << ret.first - 1 << "\n";
    cout << ret.second << "\n";

    return 0;
}