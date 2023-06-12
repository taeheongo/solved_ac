/*
    순열 next_permutation을 이용한 방식

    5개의 원소를 정렬하는 방법
    5P5 = 5! = 120
*/

#include <bits/stdc++.h>

using namespace std;

int a[5] = {1, 2, 3, 4, 5};

int main()
{
    int ret = 0;

    do
    {
        ret++;
    } while (next_permutation(a, a + 5));

    cout << ret << "\n";

    return 0;
}