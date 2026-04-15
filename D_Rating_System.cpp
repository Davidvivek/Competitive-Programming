#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    int sum=0, mx=0, delta=0, ans=0;
    for(int i=0; i<n; i++)
    {
        sum += a[i]; 
        mx = max(mx, sum);
        if(sum - mx < delta)
        {
            delta = sum - mx;
            ans = mx;
        }
    }
    cout << ans << endl;
}

int32_t main ()
{
    int t; cin >> t;
    while(t--)
    {
        solve();    
    }
}