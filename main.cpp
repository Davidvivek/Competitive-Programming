#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    int n; cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++) cin >> a[i];
    sort(a.begin(),a.end());
    int median = a[n/2];
    int cost=0;
    for(int i=0; i<n; i++)
    {
        cost += abs(a[i]-median);
    }
    cout << cost << endl;
}