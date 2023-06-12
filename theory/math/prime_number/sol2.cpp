/*
    에라토스 체는  배열이 필요하기 때문에
    문제에 따라 천만 ~ 1억 넘어가면 실패할 수 있다.

    그래서 소수 판별 함수를 아래와 같이 만들어야 한다.

    time: O(sqrt(N))
*/

#include <bits/stdc++.h>

using namespace std;

int n;

bool is_prime_number(int n)
{
    if (n == 1)
        return 0;
    if (n == 2)
        return 1;

    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
            return 0;
    }

    return 1;
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