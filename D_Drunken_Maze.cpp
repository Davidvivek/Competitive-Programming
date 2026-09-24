#include <bits/stdc++.h>
using namespace std;

struct node
{
    int r, c, d, k;
};

struct cs
{
    int dist[4][4];
    cs()
    {
        for(int i=0; i<4; i++)
        {
            for(int j=0; j<4; j++)
            {
                dist[i][j] = -1;
            }
        }
    }
};

void david_vivek()
{
    int n, m;
    cin >> n >> m;
    vector<string> g(n);
    for(int i=0; i<n; i++) cin >> g[i];

    int sr, sc, tr, tc;
    sr = sc = tr = tc = -1;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(g[i][j] == 'S')
            {
                sr = i;
                sc = j; 
            }
            if(g[i][j] == 'T')
            {
                tr = i;
                tc = j;
            }
        }
    }

    vector<vector<cs>> vis(n, vector<cs>(m));
    vector<int> dr = {-1, 1, 0, 0};
    vector<int> dc = {0, 0, -1, 1};

    queue<node> q;
    for(int d=0; d<4; d++)
    {
        int nr = sr + dr[d];
        int nc = sc + dc[d];
        if(nr>=0 && nr<n && nc>=0 && nc<m && g[nr][nc]!='#')
        {
            vis[nr][nc].dist[d][1] = 1;
            q.push({nr, nc, d, 1});
        }
    }

    while(!q.empty())
    {
        node cur = q.front();
        q.pop();

        int cd = vis[cur.r][cur.c].dist[cur.d][cur.k];

        if (cur.r == tr && cur.c == tc) 
        {
            cout << cd << "\n";
            return;
        }

        for (int nd = 0; nd < 4; nd++) 
        {
            int nk = (nd == cur.d) ? cur.k+1 : 1;
            if (nk > 3) continue;

            int nr = cur.r + dr[nd];
            int nc = cur.c + dc[nd];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && g[nr][nc] != '#') 
            {
                if (vis[nr][nc].dist[nd][nk] == -1) 
                {
                    vis[nr][nc].dist[nd][nk] = cd + 1;
                    q.push({nr, nc, nd, nk});
                }
            }
        }
    }

    cout << -1 << "\n";
}

int main ()
{
    david_vivek();
}