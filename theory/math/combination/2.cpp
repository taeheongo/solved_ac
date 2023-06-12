/*
    조합 recursive 방식

    9C4 와 같이 n C r에서 r이 4개이상이 되면 iterative 방식은 너무 많은 for문을 만들게 된다.
    그럴 땐 recursive한 방식으로 짜는게 더 좋음.

    9C4 = 9! / (4! *  5!)
        = 126
*/
#include <bits/stdc++.h>

using namespace std;

int a[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

int go(int start, vector<int> &v, int n, int r)
{
    if (v.size() == r)
        return 1;

    int ret = 0;
    for (int i = start; i < n; i++)
    {
        v.push_back(i);
        ret += go(i + 1, v, n, r);
        v.pop_back();
    }

    return ret;
}

int comb(int n, int r)
{
    int cnt = 0;
    vector<int> v;

    return go(0, v, n, r);
}

int main()
{
    cout << comb(9, 4) << "\n";

    return 0;
}