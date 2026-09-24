#include <bits/stdc++.h>
using namespace std;

#define int long long

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    long long sum = accumulate(a.begin() , a.end() , 0LL);
    int rem = sum/2;
    int ans = sum - rem;

    sort(a.rbegin() , a.rend());
    for(auto x:a)
    {
        if(rem <= 0) break;
        rem -= x;
        ans++;
    }
    cout << ans << endl;
}

int32_t main ()
{
    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}