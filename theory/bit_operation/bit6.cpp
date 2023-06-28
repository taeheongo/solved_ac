/*
    조합을 더 간단히 표현

    4C0 + 4C1 + 4C2 + 4C3 + 4C4 = 2^4
    1 + 4 + 6 + 4+ 1 = 16

    sum (i= 0 to n) nCi = 2^n
*/

#include <bits/stdc++.h>

using namespace std;

const int n = 4;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string a[n] = {"사과", "딸기", "포도", "배"};

    for (int i = 0; i < (1 << n); i++)
    {
        string ret = "";
        for (int j = 0; j < n; j++)
        {
            if (i & (1 << j))
            {
                ret += (a[j] + " ");
            }
        }
        cout << ret << "\n";
    }

    return 0;
}