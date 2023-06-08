/*
    submission : https://www.acmicpc.net/source/61870813

    n!의 10의 개수를 구하는 문제.
    10의 개수 = min(2의 개수, 5의 개수)

    일일이 다 세는 방식 brute force => 시간초과
*/

#include <bits/stdc++.h>

using namespace std;

int t, n;

int main()
{
    cin >> t;
    while (t--)
    {
        cin >> n;
        int two = 0, five = 0;
        for (; n >= 2; n--)
        {
            int num = n;
            while (num % 2 == 0)
            {
                num /= 2;
                two++;
            }

            num = n;
            while (num % 5 == 0)
            {
                num /= 5;
                five++;
            }
        }

        cout << min(two, five) << "\n";
    }

    return 0;
}