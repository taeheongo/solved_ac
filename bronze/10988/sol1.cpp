/*
    submission : https://www.acmicpc.net/source/61477622

    palindrome 판독기 짜는 문제.
    2 pointer로 풀어봄.

    time: O(N)
*/

#include <bits/stdc++.h>

using namespace std;

int l, r;
string s;

int main()
{
    cin >> s;
    r = s.size() - 1;

    while (l <= r)
    {
        if (s[l] != s[r])
        {
            cout << 0 << "\n";
            return 0;
        }
        l++;
        r--;
    }

    cout << 1 << "\n";

    return 0;
}