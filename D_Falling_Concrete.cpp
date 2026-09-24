#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x: a) cin >> x;
    set<int> s;
    for(int i=0; i<n; i++) s.insert(a[i]-i);

    int ans, cnt, prev;
    ans = cnt = prev = 0;
    bool first = 1;
    for(int x:s)
    {
        if(first || x != prev+1)
        {
            cnt = 1;
        }
        else
        {
            cnt++;
        }

        ans = max(ans, cnt);
        prev = x;
        first = false;
    }

    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}