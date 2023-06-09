/*
    submission : https://www.acmicpc.net/source/61911736

    스택
*/

#include <bits/stdc++.h>

using namespace std;

int n;
string s;
int top = 0;

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> s;

        top = 0;
        for (char c : s)
        {
            if (top == 0)
            {
                top++;
                if (c == ')')
                {
                    break;
                }
            }
            else
            {
                top = c == '(' ? ++top : --top;
            }
        }

        if (top == 0)
        {
            cout << "YES\n";
        }
        else
        {
            cout << "NO\n";
        }
    }

    return 0;
}