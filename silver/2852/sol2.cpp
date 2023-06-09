/*
    submission : https://www.acmicpc.net/source/61904855

    좀 더 직관적인 코드.
*/

#include <bits/stdc++.h>

using namespace std;

int A, B;
int n, num, a_sum, b_sum;
string t, pre_t;
const string END_TIME = "48:00";

void print_time(int sec)
{
    string mn = "0" + to_string(sec / 60);
    string sc = "0" + to_string(sec % 60);

    mn = mn.substr(mn.size() - 2, 2);
    sc = sc.substr(sc.size() - 2, 2);

    cout << mn << ":" << sc << "\n";
}

int time_to_sec(string s)
{
    int pos = s.find(':');
    string minute = s.substr(0, pos);
    string sec = s.substr(pos + 1);

    return atoi(minute.c_str()) * 60 + atoi(sec.c_str());
}

void go(int &sum, string s)
{
    sum += time_to_sec(s) - time_to_sec(pre_t);
}

int main()
{
    cin >> n;

    while (n--)
    {
        cin >> num >> t;

        if (A > B)
            go(a_sum, t);
        else if (A < B)
            go(b_sum, t);

        pre_t = t;

        if (num == 1)
            A++;
        else
            B++;
    }

    if (A > B)
        go(a_sum, END_TIME);
    else if (A < B)
        go(b_sum, END_TIME);

    print_time(a_sum);
    print_time(b_sum);

    return 0;
}