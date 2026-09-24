#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    string s; cin >> s;
    vector<int> andi(n), ori(n);
    andi[0] = ori[0] = s[0]-'0';
    for(int i=1; i<n; i++)
    {
        andi[i] = andi[i-1]&(s[i] - '0');
        ori[i] = ori[i-1]|(s[i] - '0');
    }

    const int INF = 1e9;
    vector<int> dp1(n, INF), dp2(n, INF);
    if(s[0] == '0')
    {
        dp1[0] = 0;
    }
    else
    {
        dp2[0] = 0;
    }

    for(int i=1; i<n; i++)
    {
        vector<pair<int,int>> rep;
        rep.push_back({s[i]-'0', 0});
        rep.push_back({andi[i], 1});
        rep.push_back({ori[i], 1});

        for(auto x:rep)
        {
            if(x.first == 0)
            {
                dp1[i] = min(dp1[i] , dp1[i-1]+x.second);
            }
            else
            {
                dp2[i] = min(dp2[i], dp1[i - 1] + x.second);
                dp2[i] = min(dp2[i], dp2[i - 1] + x.second);
            }
        }
    }

    cout << min(dp1[n-1] , dp2[n-1]) << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}