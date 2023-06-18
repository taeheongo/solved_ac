/*
    submission : https://www.acmicpc.net/source/62223374

    dfs 시관초과
    처음 풀었던 풀이인데 9, 3, 1을 순열로 3P3 = 3! / 1!  = 6

    {1, 3, 9},
    {1, 9, 3},
    {3, 1, 9},
    {3, 9, 1},
    {9, 1, 3},
    {9, 3, 1},

    이렇게 6가지가 나오는데
    이렇게해서 n개 모두 0, 0, 0이 되는 최소 공격 횟수를 구하는 것.

    이 문제를 보고 그리디로 시도해보다가 (https://www.acmicpc.net/source/62204618)
    그리디로 풀 수 없다는 것을 알개되고, brute force로 풀어봤다.

    위 순열 6가지에 대해서 recursive하게 구현했고, recursive = 스택을 의미하고,
    recursive tree도 tree이므로 이런 recursive한 방식은 dfs를 의미한다.

    12 10 4 가 주어졌다면

                                                               {12, 10, 4}
                                  {11, 7, 0}   {11, 1, 1}    {9, 9, 0}    {9, 1, 3},  {3, 9, 1}    {3,  7,  3}
                  {10, 4, 0}
             ...
    {0, 0, 0}

    dfs는 이렇게 {0, 0, 0}에 도달했다고 해도 최단거리에 대한 보장이 없기 때문에 결국 모든 노드를 다 순회 해서 {0,0, 0}이 되는 모든 공격횟수를 다 구해서 최솟값을 얻어야만 한다.

    1 <= 체력 <= 60,  1 <= N <= 3

    time <= 1 + 6 + 6^2 + ... + 6^60
*/

#include <bits/stdc++.h>

using namespace std;

int n, ret;
int a[3];
int dmg[3] = {9, 3, 1};

void print()
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    cout << "\n";
}

int go(int start)
{
    print();
    if (a[0] <= 0 && a[1] <= 0 && a[2] <= 0)
    {
        return 1;
    }

    if (start == n)
    {
        return go(0) + 1;
    }

    int cnt = 10000;
    for (int i = start; i < n; i++)
    {
        if (a[i] <= 0)
            continue;
        swap(a[i], a[start]);
        a[start] -= dmg[start];
        cnt = min(cnt, go(start + 1));
        a[start] += dmg[start];
        swap(a[i], a[start]);
    }

    return cnt;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    cout << go(0) << "\n";

    return 0;
}