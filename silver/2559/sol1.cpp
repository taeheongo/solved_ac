/*
    submission : https://www.acmicpc.net/source/61529734

    sliding window.
    이 문제의 경우는 정해진 갯수의 연속된 원소의 합 중 최댓값을 구하는 문제.
    만약 정해진 갯수가 아니라 그냥 최댓값을 물었다면 주석처럼 케이스 분류를 해야 한다.

*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int max_sum, cur_sum;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> k;

    vector<int> v(n, 0);

    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }

    for (int i = 0; i < k; i++)
    {
        max_sum += v[i];
    }

    cur_sum = max_sum;
    for (int i = k; i < n; i++)
    {
        cur_sum += v[i];
        cur_sum -= v[i - k];
        max_sum = max(max_sum, cur_sum);
    }

    cout << max_sum << "\n";

    return 0;
}

/*
    max = -3 -> 2
    next = 2

    -3 2

    max = -3 -> -2
    next = -2

    -3 -2

    max = 3 -> 5
    next = 5

    3 2

    max = 3 -> 1
    next = 1

    3 -2
*/