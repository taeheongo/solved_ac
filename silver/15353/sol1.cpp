/*
    submission : https://www.acmicpc.net/source/64699642
*/

#include <bits/stdc++.h>

using namespace std;

string a, b;

string plusAB(string a, string b)
{
    int size = min(a.size(), b.size());
    int carry = 0;
    string ret = "";

    for (int i = 0; i < size; i++)
    {
        int num1 = a[a.size() - 1 - i] - '0';
        int num2 = b[b.size() - 1 - i] - '0';
        int num3 = num1 + num2 + carry;
        int num4 = num3 % 10;
        carry = num3 / 10;

        ret = to_string(num4) + ret;
    }

    if (a.size() > b.size())
    {
        for (int i = size; i < a.size(); i++)
        {
            int num1 = a[a.size() - 1 - i] - '0' + carry;
            int num2 = num1 % 10;
            carry = num1 / 10;

            ret = to_string(num2) + ret;
        }
    }
    else if (a.size() < b.size())
    {
        for (int i = size; i < b.size(); i++)
        {
            int num1 = b[b.size() - 1 - i] - '0' + carry;
            int num2 = num1 % 10;
            carry = num1 / 10;

            ret = to_string(num2) + ret;
        }
    }

    if (carry)
    {
        ret = "1" + ret;
    }

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