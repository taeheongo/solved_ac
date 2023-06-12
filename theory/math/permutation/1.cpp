/*
    순열 recursive 방식

    5P3 = 5! / (5-3)! = 60
*/

#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int go(int n, int r, int depth)
{
    if (depth == r)
    {
        return 1;
    }

    int ret = 0;
    for (int i = depth; i < n; i++)
    {
        swap(a[i], a[depth]);
        ret += go(n, r, depth + 1);
        swap(a[i], a[depth]);
    }

    return ret;
}

int permutation(int n, int r)
{
    return go(n, r, 0);
}

int main()
{
    cout << permutation(5, 3) << "\n";

    return 0;
}