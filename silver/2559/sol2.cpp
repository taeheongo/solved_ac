/*
    submission : https://www.acmicpc.net/source/61531077

    prefix sum을 이용한 풀이.
*/

#include <bits/stdc++.h>

using namespace std;

int n, k;
int p_sum[100001], tmp, ret = -10000001;

int main()
{
    cin >> n >> k;

    for (int i = 1; i <= n; i++)
    {
        cin >> tmp;
        p_sum[i] = p_sum[i - 1] + tmp;
    }

    for (int i = k; i <= n; i++) // k+1 아니고 k부터
    {
        ret = max(p_sum[i] - p_sum[i - k], ret);
    }

    cout << ret << "\n";

    return 0;
}