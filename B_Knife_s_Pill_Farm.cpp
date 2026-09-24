#include <bits/stdc++.h>
using namespace std;

#define int long long
void David_Vivek()
{
    int n; cin >> n;
    int m; cin >> m;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    priority_queue<int> pq;
    int sum = 0;
    int ans = LLONG_MIN;
    for(auto x:a)
    {
        if(pq.size() == m-1)
        {
            ans = max(ans, 1LL*m*x-sum);
        }

        pq.push(x);
        sum += x;

        if(pq.size() > m-1)
        {
            sum -= pq.top();
            pq.pop();
        }
    }
    cout << ans << endl;
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