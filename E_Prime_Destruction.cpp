#include <bits/stdc++.h>
using namespace std;

const int MAXN = 200005;
vector<int> factors[MAXN];

void precompute()
{
    for(int p = 2; p < MAXN; p++)
    {
        if(factors[p].empty())
        {
            for(int j = p; j < MAXN; j += p)
            {
                factors[j].push_back(p);
            }
        }
    }
}

void David_Vivek()
{
    int n; cin >> n;
    int k; cin >> k;
    vector<int> a(n);
    for(auto &x: a) cin >> x;

    vector<long long> dp(n + 1, 1e18);
    for(int i = 1; i <= n; i++)
    {
        if(i <= k)
        {
            dp[i] = 0;
            continue;
        }

        for(int p : factors[i])
        {
            dp[i] = min(dp[i], 1LL + p * dp[i / p]);
        }
    }

    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans += dp[a[i]];
    }
    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    precompute();

    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}