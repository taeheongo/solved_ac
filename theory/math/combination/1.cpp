/*
    조합 iteraitve 방식

    5 comb 3 = 5! / (3! * 2!) = 10
*/
#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = i + 1; j < 5; j++)
        {
            for (int k = j + 1; k < 5; k++)
            {
                printf("%d %d %d\n", a[i], a[j], a[k]);
            }
        }
    }

    cout << "\n";

    for (int i = 4; i >= 0; i--)
    {
        for (int j = i - 1; j >= 0; j--)
        {
            for (int k = j - 1; k >= 0; k--)
            {
                printf("%d %d %d\n", a[i], a[j], a[k]);
            }
        }
    }

    return 0;
}