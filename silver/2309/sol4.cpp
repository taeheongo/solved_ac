/*
submission : https://www.acmicpc.net/source/61443298

c++에서 제공하는 next_permutation을 이용한 풀이.
*/

#include <bits/stdc++.h>

using namespace std;

int a[9];

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> a[i];
    }

    sort(a, a + 9);

    do
    {
        int sum = accumulate(a, a + 7, 0);
        if (sum == 100)
            break;
    } while (next_permutation(a, a + 9));

    for (int i = 0; i < 7; i++)
    {
        cout << a[i] << "\n";
    }

    return 0;
}