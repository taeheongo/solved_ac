/*
    submission : https://www.acmicpc.net/source/64691412

    기존 split함수에서는 Input에서 erase를 하는 방식인데
    시간초과가 걸려서
    split함수에서 erase부분을 없앴다.

    배열에 있는 수의 최대 개수는 10^5개인데
    split함수에서 ,는 최대 10^5-1개가 나올수 있고
    그렇다면 split함수내에 있는 while문은 10^5번 돌아가는데
    while문에서 erase함수를 사용하게되면 또 10^5을 사용하게 된다.
    erase부분을 사용하지 않는 방식으로 split함수를 구현하면 통과.
*/

#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;

deque<string> split(string input, string d)
{
    deque<string> ret;
    long long pos = 0;
    int start = 0;

    while ((pos = input.find(d, start)) != string::npos)
    {
        string token = input.substr(start, pos - start);
        ret.push_back(token);
        start += token.size() + d.size();
    }
    if (input != "")
        ret.push_back(input.substr(start, input.size() - start));

    return ret;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> t;

    while (t--)
    {
        cin >> p;
        cin >> n >> s;

        bool dir = true;
        bool error = false;

        deque<string> nums = split(s.substr(1, s.size() - 2), ",");

        for (char c : p)
        {
            if (c == 'R')
            {
                dir = !dir;
            }
            else if (c == 'D')
            {
                if (nums.empty())
                {
                    error = true;
                    break;
                }

                if (dir)
                    nums.pop_front();
                else
                    nums.pop_back();
            }
        }

        if (error)
        {
            cout << "error\n";
            continue;
        }

        if (!dir)
        {
            reverse(nums.begin(), nums.end());
        }

        cout << "[";
        for (int i = 0; i < nums.size(); i++)
        {
            cout << nums[i];
            if (i != nums.size() - 1)
                cout << ",";
        }
        cout << "]\n";
    }

    return 0;
}