/*
제출 : https://www.acmicpc.net/source/61446276

조합을 이용한 풀이

9C7을 recursive 한 방식으로 구하고 그 중에 합이 100이 되면 return.

*/

#include <bits/stdc++.h>

using namespace std;

vector<int> v(9, 0), ret;
int sum;

void go(int start)
{
    if (ret.size() == 7)
    {
        sum = accumulate(ret.begin(), ret.end(), 0);

        return;
    }

    for (int i = start; i < 9; i++)
    {
        ret.push_back(v[i]);
        go(start + 1);
        if (sum == 100)
            break;
        ret.pop_back();
    }
}

int main()
{
    for (int i = 0; i < 9; i++)
    {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    go(0);

    for (int n : ret)
    {
        cout << n << "\n";
    };

    return 0;
}