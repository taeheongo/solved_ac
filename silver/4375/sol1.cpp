/*
    submission : https://www.acmicpc.net/source/61729040

    모듈러 연산
*/

#include <bits/stdc++.h>

using namespace std;

int n;

int main()
{

    while (cin >> n)
    {
        int num = 1;
        int cnt = 1;
        int c = 10 % n;

        while (num % n)
        {
            num = (num * c % n + 1) % n;
            cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}

// 1
// 11 = 1 * 10 + 1
// 111 = 11 * 10 + 1