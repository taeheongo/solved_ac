#include <bits/stdc++.h>

using namespace std;

struct A
{
    int val;
};

vector<A> v;

int main()
{
    for (int i = 0; i < 10; i++)
    {
        A tmp_a{i};

        v[i] = tmp_a;
    }

    return 0;
}