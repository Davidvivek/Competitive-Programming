#include <bits/stdc++.h>
using namespace std;

static const long long MOD = 1000000007;

inline long long modpow(long long a, long long e)
{
    long long r = 1;
    a %= MOD;
    while (e)
    {
        if (e & 1) r = (r * a) % MOD;
        a = (a * a) % MOD;
        e >>= 1;
    }
    return r;
}

void solve()
{
    long long m;
    cin >> m;
    long long exp = (m - 1) * (m - 1);
    cout << modpow(2, exp) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
