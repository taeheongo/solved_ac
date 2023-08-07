/*
    submission : https://www.acmicpc.net/source/64694159

    split함수를 사용하지 않아도 된다.
*/

#include <bits/stdc++.h>

using namespace std;

int t, n;
string p, s;

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

        deque<string> nums;

        string x = "";
        for (char c : s)
        {
            if (c >= '0' && c <= '9')
            {
                x += c;
            }
            else if (c == ',')
            {
                nums.push_back(x);
                x = "";
            }
        }
        if (x != "")
        {
            nums.push_back(x);
        }

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