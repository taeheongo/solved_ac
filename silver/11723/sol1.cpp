#include <bits/stdc++.h>

using namespace std;

int m, x, n;
char s[11];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    scanf(" %d", &m);

    while (m--)
    {
        scanf(" %s %d", s, &x);

        if (s[0] == 'a' && s[1] == 'd')
        {
            n |= 1 << (x - 1);
        }
        else if (s[0] == 'r')
        {
            n &= ~(1 << (x - 1));
        }
        else if (s[0] == 'c')
        {
            if (n & (1 << (x - 1)))
            {
                cout << 1 << "\n";
            }
            else
            {
                cout << 0 << "\n";
            }
        }
        else if (s[0] == 't')
        {
            /*
                xor
                10 1
                11 0
                00 0
                01 1
            */
            n ^= (1 << (x - 1));
        }
        else if (s[0] == 'a' && s[1] == 'l')
        {
            n = (1 << 20) - 1;
        }
        else if (s[0] == 'e')
        {
            n = 0;
        }
    }

    return 0;
}
