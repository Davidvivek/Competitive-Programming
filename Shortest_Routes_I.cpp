#include <bits/stdc++.h>
using namespace std;

vector<long long> dijkstra (vector<vector<pair<int,int>>>& adj)
{
    int n = adj.size();
    long long INF = 1e15;

    vector<long long> dist(n, INF);
    dist[0] = 0;
    priority_queue<pair<long long, int> , vector<pair<long long, int>> , greater<pair<long long, int>>> pq;
    pq.push({0,0});
    while(!pq.empty())
    {
        int cur_node = pq.top().second;
        long long cur_dist = pq.top().first;
        pq.pop();

        if (cur_dist > dist[cur_node]) continue;

        for(auto p : adj[cur_node])
        {
            int adj_node = p.first;
            int adj_dist = p.second;
            if(cur_dist != INF && dist[adj_node] > cur_dist + adj_dist)
            {
                dist[adj_node] = cur_dist+adj_dist;
                pq.push({dist[adj_node] , adj_node});
            }
        }
    }
    return dist;
}

int main ()
{
    int n, m;
    cin >> n >> m;
    
    vector<vector<pair<int,int>>> adj(n);
    for(int i=0; i<m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w; // represents an edge between u and v with weight w
        u--; v--;
        adj[u].push_back({v,w});
        // adj[v].push_back({u,w});
    }

    vector<long long> ans = dijkstra(adj);
    for(auto x:ans) cout << x << " ";
    cout << endl;
}