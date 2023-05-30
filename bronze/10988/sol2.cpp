/*
    submission : https://www.acmicpc.net/source/61477955

    이건 reverse로 풀기.
*/

#include <bits/stdc++.h>

using namespace std;

string s;

int main()
{
    cin >> s;

    string s2(s);
    reverse(s2.begin(), s2.end());

    if (s == s2)
    {
        cout << 1 << "\n";
    }
    else
    {
        cout << 0 << "\n";
    }

    return 0;
}