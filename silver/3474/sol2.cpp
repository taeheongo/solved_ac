/*
    submission : https://www.acmicpc.net/source/61871029

    이거는 수에 대한 감각이 요구되는 부분이라 외우셈.

    10! 의 2의 개수를 구한다고 하면

    1 2 3 4 5 6 7 8 9 10
      1   1   1   1    1
          1       1
                  1

    5 + 2 + 1 = 8개

    해석 :
    1~10까지 2의 배수의 개수
        + 1~10까지 4의 배수의 개수
        + 1~10까지 8의 배수의 개수 = 8개

    time: O(t * (log2(n) + log5(n))) (단, 1 <= n <= 1000000000)
*/

#include <bits/stdc++.h>

using namespace std;

int t, num, n, cnt_2, cnt_5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;
    while (t--)
    {
        cnt_2 = 0;
        cnt_5 = 0;
        cin >> num;

        for (int i = 2; i <= num; i *= 2)
        {
            cnt_2 += num / i;
        }
        for (int i = 5; i <= num; i *= 5)
        {
            cnt_5 += num / i;
        }

        cout << min(cnt_2, cnt_5) << "\n";
    }

    return 0;
}

/*

*/