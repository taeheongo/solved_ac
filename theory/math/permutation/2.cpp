/*
    순열 iterative 방식

    5P3 = 5! / (5-3)! = 60
*/

#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int main()
{
    int ret = 0;
    for (int i = 0; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            for (int k = 2; k < 5; k++)
            {
                swap(a[0], a[i]);
                swap(a[1], a[j]);
                swap(a[2], a[k]);
                ret++;
                swap(a[2], a[k]);
                swap(a[1], a[j]);
                swap(a[0], a[i]);
            }
        }
    }

    cout << ret << "\n";

    return 0;
}