#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e18;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<pair<int,int>>> adj(n + 1);

    for(int i = 0; i < m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;

        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    vector<long long> dist(n + 1, INF);
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<pair<long long,int>>> pq;

    dist[1] = 0;
    pq.push({0, 1});

    while(!pq.empty())
    {
        auto top = pq.top();
        pq.pop();

        long long d = top.first;
        int node = top.second;

        if(d > dist[node]) continue;

        for(auto x : adj[node])
        {
            int next = x.first;
            int weight = x.second;

            if(dist[node] + weight < dist[next])
            {
                dist[next] = dist[node] + weight;
                pq.push({dist[next], next});
            }
        }
    }

    for(int i = 2; i <= n; i++)
    {
        if(dist[i] == INF) cout << -1 << "\n";
        else cout << dist[i] << "\n";
    }

    return 0;
}