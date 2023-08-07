#include <bits/stdc++.h>

using namespace std;

vector<string> split(string s, string d)
{
    vector<string> ret;
    long long pos = 0;

    while ((pos = s.find(d)) != string::npos)
    {
        string tmp = s.substr(0, pos);
        ret.push_back(tmp);
        s.erase(0, tmp.size() + d.size());
    }
    ret.push_back(s);

    return ret;
}

int main()
{
    string s = "hello world goodbye world";

    vector<string> ret = split(s, " ");
    for (auto str : ret)
    {
        cout << str << "\n";
    }

    return 0;
}