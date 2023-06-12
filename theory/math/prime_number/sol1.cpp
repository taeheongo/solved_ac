/*
    에라토스테네스의 체

    time: O(N * sqrt(N)) 정도
*/

#include <bits/stdc++.h>

using namespace std;

int n;

bool is_prime_number(int n)
{
    vector<int> ret(n + 1, 1);

    for (int i = 2; i <= n; i++)
    {
        if (ret[i] == 0)
            continue;
        // 여기로 넘어오면 일단 i는 소수인 거임.
        // 그리고 i*i부터 시작해서 i의 배수 전부 제거.
        for (int j = i * i; j <= n; j += i)
        {
            ret[j] = 0;
        }
    }

    return ret[n];
}

int main()
{
    cin >> n;

    if (is_prime_number(n))
        printf("%d는 소수가 맞음\n", n);
    else
        printf("%d는 소수가 아님\n", n);

    return 0;
}