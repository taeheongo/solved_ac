/*
    submission : https://www.acmicpc.net/source/64808930

    나올 수 있는 모든 경우의 수를 다 고려하려면 하나 하나 다 해봐야 함.
        => 머리속으로 하는 것보다 그려보면서 해야 함.

    주의 해야할 점 :

    문제에서 모든 사람의 키 < 2^31 이라고 했으니 딱 int에 들어가지지만.
    모든 사람을 짝 지을 수 있다고 하면
    500000 C 2

    500000! / 2! * (500000 - 2)!

    (500000 * 499999) / 2! > 10^11
    최대 1000억을 넘어간다.
    int는 최대 20억정도니까 long long을 써야한다. 안그러면 실패함. (https://www.acmicpc.net/source/64805571)
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll n, ret, num;

struct A
{
    ll num, cnt;
};

stack<A> stk;

int main()
{
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> num;

        if (stk.empty())
        {
            stk.push({num, 1});
        }
        else
        {
            if (stk.top().num == num)
            {
                ret += stk.top().cnt;
                if (stk.size() > 1)
                {
                    ret++;
                }
                stk.top().cnt++;
            }
            else if (stk.top().num > num)
            {
                ret++;
                stk.push({num, 1});
            }
            else
            {
                int total_cnt = 0;

                while (stk.size() && stk.top().num < num)
                {
                    total_cnt += stk.top().cnt;
                    stk.pop();
                }

                ret += total_cnt;

                if (stk.size())
                {
                    if (stk.top().num == num)
                    {
                        ret += stk.top().cnt;
                        if (stk.size() > 1)
                        {
                            ret++;
                        }
                        stk.top().cnt++;
                    }
                    else if (stk.top().num > num)
                    {
                        ret++;
                        stk.push({num, 1});
                    }
                }
                else
                {
                    stk.push({num, 1});
                }
            }
            // printf("ret : %d\n", ret); // debug
        }
    }

    cout << ret << '\n';

    return 0;
}