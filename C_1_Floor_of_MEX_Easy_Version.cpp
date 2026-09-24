#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    vector<pair<int,int>> bad_divs;
    for(int i=0; i<n; i++)
    {
        int k = i+1;
        int mex = a[i];
        bad_divs.push_back({k*mex, k*(mex+1)-1});
    }

    vector<int> d(n+1);
    for(auto x:bad_divs)
    {
        int l = x.first;
        int r = x.second;
        d[min(n,l)]++;
        d[min(n,r+1)]--;
    }

    int cur_sum=0;
    vector<int> s;
    for(int i=0; i<n; i++)
    {
        cur_sum += d[i];
        if(!cur_sum) s.push_back(i);
    }

    cout << s.size() << '\n';
    for(auto x:s) cout << x << " ";
    cout << '\n';
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