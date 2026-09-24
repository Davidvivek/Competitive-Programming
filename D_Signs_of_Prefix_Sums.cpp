#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> pref(n), a(n);

    s = "0"+s;
    if (s.npos != s.find("00")) cout << "-1\n";
    else if (s.npos != s.find("+--+") || s.npos != s.find("-++-")) cout << "3\n";
    else if (s.npos != s.find("+-") || s.npos != s.find("-+")) cout << "2\n";
    else
    {
        bool flag = false;
        int cur_cnt=1;
        for(auto ch:s)
        {
            if(ch == '0')
            {
                flag |= (cur_cnt%2 == 0);
                cur_cnt=0;
            }
            else
            {
                cur_cnt++;
            }
        }

        if(flag)
        {
            cout << "2\n";
            return;
        }
        cout << "1\n";
    }

    return;
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}