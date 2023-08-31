/*
    배열은 백만이 최대. 10^6
    천만부터는 컴파일 에러 (스택 프레임 사이즈 초과)

    test.cpp:5:5: warning: stack frame size (2525163616) exceeds limit (4294967295) in 'main' [-Wframe-larger-than]
    int main()
        ^
    1 warning generated.
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
    // int a[10000000]; // 컴파일 에러
    // vector<int> v[10000000]; // 런타임 에러
    int a[1000000];

    return 0;
}
