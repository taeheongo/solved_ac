/*
    submission : https://www.acmicpc.net/source/61692445

    a,b,c가 전부 20억이상이므로 for문으로 하면 O(N)은 시관초과날 것.
    반복문 횟수를 O(logN)으로 줄일수 있는 방법을 생각해야함.
    그리고 곱하는 수도 20억이상이므로 long long으로 담을 수 없으므로 모듈러 연산법칙을 사용해야함.

    분할정복 + 모듈러 연산

    time : O(logN)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll a, b, c;

ll go(int n)
{
    if (n == 1)
        return a % c;

    ll ret = go(n / 2);
    ret *= ret;

    if (ret >= c)
        ret %= c;

    if (n & 1)
    {
        ret *= a % c;
        if (ret >= c)
            ret %= c;
    }

    return ret;
}

int main()
{
    cin >> a >> b >> c;

    cout << go(b) << "\n";

    return 0;
}