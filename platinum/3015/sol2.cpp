/*
    submission ; https://www.acmicpc.net/source/64828771

    solution 1과 같은 논리지만, 훨씬 더 짧고 간결한 코드.
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n, num;
ll ret;
stack<pair<int, int>> stk;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n;

    while (n--)
    {
        cin >> num;

        int cnt = 1;
        while (stk.size() && stk.top().first <= num)
        {
            ret += stk.top().second;

            if (stk.top().first == num)
            {
                cnt = stk.top().second + 1;
            }

            stk.pop();
        }

        if (stk.size())
        {
            ret++;
        }

        stk.push({num, cnt});
    }

    cout << ret << "\n";

    return 0;
}