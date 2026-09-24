#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n); 
    for(auto &x:a) cin >> x, x--;

    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;

        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    string ans(n, '0');
    for(int u=0; u<n; u++)
    {
        map<int,int> mp;
        for(auto v:adj[u]) mp[a[v]]++;
        mp[a[u]]++;
        for(auto x:mp) if(x.second >= 2) ans[x.first] = '1';
    }
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}