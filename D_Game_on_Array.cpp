#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n; cin >> n;
    map<int, int> freq;
    int s=0, sum=0;
    for(int i=0; i<n; i++)
    {
        int x; cin >> x;
        if(x&1) freq[x]++ , s += (x-1);
        else s += x;
        sum += x;
    }

    int alice = s/2;
    vector<int> bob;
    for(auto x:freq) bob.push_back(x.second);
    sort(bob.rbegin() , bob.rend());
    for(int i=0; i< (int)bob.size(); i+=2) alice+=bob[i];
    cout << alice << " " << sum-alice << endl;

    return;
}

int32_t main ()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; 
    cin >> t;

    while(t--)
    {
        solve();
    }
    return 0;
}