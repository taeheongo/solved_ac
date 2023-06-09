/*
    submission : https://www.acmicpc.net/source/61902894

    구현
    전의 값을 기억해야하는 문제 => prev 변수로 전의 값 저장.
*/

#include <bits/stdc++.h>

using namespace std;

int n, num, pre_num;
string t, pre_t;
int t_arr[3], score[3];
const string END_TIME = "48:00";

int time_to_sec(string s)
{
    int pos = s.find(':');
    string minute = s.substr(0, pos);
    string sec = s.substr(pos + 1);

    return atoi(minute.c_str()) * 60 + atoi(sec.c_str());
}

void print_time(int sec)
{
    string mn = "0" + to_string(sec / 60);
    string sc = "0" + to_string(sec % 60);

    mn = mn.substr(mn.size() - 2, 2);
    sc = sc.substr(sc.size() - 2, 2);

    cout << mn << ":" << sc << "\n";
}
int main()
{
    cin >> n;

    while (n--)
    {
        cin >> num >> t;
        score[num]++;

        if (score[1] == score[2])
        {
            t_arr[pre_num] += time_to_sec(t) - time_to_sec(pre_t);
            pre_num = 0;
        }
        else
        {
            if (pre_num == 0)
            {
                pre_t = t;
                pre_num = num;
            }
        }
    }

    if (score[1] != score[2])
    {
        t_arr[pre_num] += time_to_sec(END_TIME) - time_to_sec(pre_t);
    }

    for (int i = 1; i <= 2; i++)
    {
        print_time(t_arr[i]);
    }

    return 0;
}