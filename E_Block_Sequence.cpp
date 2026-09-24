#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    vector<int> dp(n+1, -1);
    dp[n] = 0;
    for(int i=n-1; i>=0; i--)
    {
        dp[i] = dp[i+1]+1;
        
        int j = i+a[i]+1;
        if(j<=n)
        {
            dp[i] = min(dp[i],dp[j]);
        }
    }

    cout << dp[0] << endl;
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}