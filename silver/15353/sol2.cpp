/*
    submission : https://www.acmicpc.net/source/64734439
*/

#include <bits/stdc++.h>

using namespace std;

string a, b;

string plusAB(string a, string b)
{
    int sum = 0;
    int carry = 0;
    string ret = "";

    while (a.size() || b.size() || carry)
    {
        sum += carry;

        if (a.size())
        {
            sum += a.back() - '0';
            a.pop_back();
        }

        if (b.size())
        {
            sum += b.back() - '0';
            b.pop_back();
        }

        ret += sum % 10 + '0';
        carry = sum / 10;
        sum = 0;
    }

    reverse(ret.begin(), ret.end());

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> a >> b;
    cout << plusAB(a, b) << "\n";

    return 0;
}