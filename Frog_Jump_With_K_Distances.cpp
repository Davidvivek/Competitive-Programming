#include <bits/stdc++.h>
using namespace std;

int solve(int n, int k, vector<int> &h, vector<int> &dp)
{
    dp[0] = 0;
    for(int i=1; i<n; i++)
    {
        int minSteps = INT_MAX;
        for(int j=1; j<=k; j++)
        {
            if(i-j >= 0)
            {
                int x = dp[i-j] + abs(h[i]-h[i-j]);
                minSteps = min(x, minSteps);
            }
        }
        dp[i] = minSteps;
    }
    return dp[n-1];
}

int main ()
{
    int n; cin >> n;
    int k; cin >> k;
    vector<int> h(n); 
    for(auto &x:h) cin >> x;
    
    vector<int> dp(n, -1);
    cout << solve(n, k, h, dp) << endl;
}