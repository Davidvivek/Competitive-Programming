#include <bits/stdc++.h>
using namespace std;

#define int long long

bool check(int m, vector<pair<int,int>> &a, int sum)
{
    int n = a.size();
    for(int i=0; i<n; i++)
    {
        if(a[i].first == m) return true;
    }

    int q = 1;
    int extra = 0;
    int cur = m-1;

    for(int i=n-1; i>=0; i--)
    {
        int val = a[i].first;
        int cnt = a[i].second;

        if(val == 0) break;

        if(val > cur)
        {
            extra += cnt;
            continue;
        }

        if(val < cur)
        {
            int gap = cur-val;
            if(gap > 60 || q > (sum >> gap)) q = sum + 1;
            else q <<= gap;
            cur = val;
        }

        if(cnt >= q)
        {
            extra += (cnt - q);
        }
        else
        {
            q += (q-cnt);
            q = min(q, sum+1);
        }

        cur--;
    }

    if(cur >= 0)
    {
        int gap = cur;
        if(gap > 60 || q > (sum >> gap)) q = sum + 1;
        else q <<= gap;
    }

    int zeroes = 0;
    if(!a[0].first) zeroes += a[0].second;

    return (zeroes + extra) >= q;
}

void David_Vivek()
{
    int n; cin >> n;
    vector<pair<int,int>> a(n);

    int mx = 0;
    int sum = 0;
    for(int i=0; i<n; i++) 
    {
        cin >> a[i].first >> a[i].second;
        mx = max(mx, a[i].first);
        sum += a[i].second;
    }
    sort(a.begin(), a.end());

    int lo = mx;
    int hi = mx+sum+1;
    int ans = lo;
    while(lo<=hi)
    {
        int mid = lo + (hi-lo)/2;
        if(check(mid, a, sum))
        {
            ans = mid;
            lo = mid+1;
        }
        else
        {
            hi = mid-1;
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