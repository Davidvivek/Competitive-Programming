#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;
    vector<vector<int>> adj(n);
    for(int i=0; i<n-1; i++)
    {
        int u, v, x, y;
        cin >> u >> v >> x >> y;
        u--; v--;
        if(x>=y) adj[v].push_back(u);
        else adj[u].push_back(v);
    }

    vector<int> topoSort;
    vector<int> inDeg(n,0);
    for(int i=0; i<n; i++)
    {
        for(auto v:adj[i])
        {
            inDeg[v]++;
        }
    }
    queue<int> q;
    for(int i=0; i<n; i++)
    {
        if(!inDeg[i]) q.push(i);
    }

    while(!q.empty())
    {
        int node = q.front();
        q.pop();
        topoSort.push_back(node);
        for(auto v:adj[node])
        {
            inDeg[v]--;
            if(inDeg[v]==0) q.push(v);
        }
    }

    vector<int> p(n);
    for (int i=0; i<n; i++) 
    {
        p[topoSort[i]] = i+1;
    }

    for (int i=0; i<n; i++) 
    {
        cout << p[i] << " ";
    }
    cout << '\n';
}

int main ()
{
    int t; 
    cin >> t;
    while(t--)
    {
        solve();
    }
}