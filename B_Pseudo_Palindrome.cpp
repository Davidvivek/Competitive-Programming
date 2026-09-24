#include <bits/stdc++.h>
using namespace std;

#define int long long
void David_Vivek()
{
    int n; cin >> n;
    int d; cin >> d;
    vector<int> a(n); 
    for(auto &x:a) cin >> x;

    // if(n&1)
    // {
    //     cout << "NO\n";
    //     return;
    // }

    sort(a.begin() , a.end());
    
    if(n%2 == 0)
    {
        for(int i=0; i<n-1; i+=2)
        {
            if(abs(a[i+1]-a[i])>d)
            {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }

    int m = n/2;
    vector<bool> pref(m+1, true);
    vector<bool> suff(m+1, true);

    for (int i = 0; i < m; ++i) 
    {
        pref[i+1] = pref[i] && ((a[2*i+1]-a[2*i]) <= d);
    }
    
    for (int i = m - 1; i >= 0; --i) 
    {
        suff[i] = suff[i+1] && ((a[2*i+2]-a[2*i+1]) <= d);
    }

    for (int i = 0; i <= m; ++i) 
    {
        if (pref[i] && suff[i]) 
        {
            cout << "YES\n";
            return;
        }
    }
    cout << "NO\n";
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}