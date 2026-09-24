#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;

typedef __gnu_pbds::tree<int, __gnu_pbds::null_type, less<int>, __gnu_pbds::rb_tree_tag, __gnu_pbds::tree_order_statistics_node_update> ordered_set;

void David_Vivek()
{
    int n; cin >> n;
    vector<pair<int,int>> a(n);
    for(int i=0; i<n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    sort(a.begin(), a.end(), [](auto &x, auto &y)
    {
        if(x.first != y.first) return x.first < y.first;
        return x.second > y.second;
    });

    ordered_set os;
    long long ans = 0;

    for(int i=0; i<n; i++)
    {
        int r = a[i].second;
        int smaller = os.order_of_key(r);
        ans += (i-smaller);
        os.insert(r);  
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