#include <bits/stdc++.h>
using namespace std;
static const int MOD = 1e9+7;

int main ()
{
    int n, k;
    cin >> n >> k;
    
    int dp[n+1][k+1] = {0};
    for(int x=1; x<=n; x++)
    {
        dp[x][1] = 1;
    }
    for(int len=1; len<k; len++)
    {
        for(int x=1; x<=n; x++)
        {
            if(dp[x][len] == 0) continue;
            for(int m=x; m<=n; m+=x)
            {
                dp[m][len+1] = (dp[m][len+1] + dp[x][len])%MOD;
            }
        }
    }
    int ans=0;
    for(int x=1; x<=n; x++)
    {
        ans = (ans+dp[x][k])%MOD;
    }
    cout << ans << endl;
}