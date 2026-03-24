#include <bits/stdc++.h>
using namespace std;
 
int numberOfRooms(vector<string>& grid)
{
    int n = grid.size(); //number of rows
    int m = grid[0].size(); //number of char's in each row
 
    vector<vector<int>> visited(n, vector<int> (m,0)); //to mark the cells visited
 
    int rooms=0;
 
    queue<pair<int,int>> q;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(visited[i][j]==0 && grid[i][j]=='.')
            {
                rooms++;
                q.push({i,j});
                vector<int> dx = {1,0,-1,0};
                vector<int> dy = {0,-1,0,1};
                visited[i][j] = 1;
                while(!q.empty())
                {
                    int row = q.front().first;
                    int col = q.front().second;
                    q.pop();
 
                    for(int k=0; k<4; k++)
                    {
                        int nrow = row + dx[k];
                        int ncol = col + dy[k];
                        if(nrow<n && nrow>=0 && ncol<m && ncol>=0 && grid[nrow][ncol]=='.' && visited[nrow][ncol]==0)
                        {
                            visited[nrow][ncol] = 1;
                            q.push({nrow,ncol});
                        }
                    }
                }
            }
        }
    }
 
    return rooms;
}
 
int main ()
{
    int n, m;
    cin >> n >> m;
    vector<string> grid(n);
    for(int i=0; i<n; i++)
    {
        cin >> grid[i];
    }
 
    int count = numberOfRooms(grid);
    cout << count << endl;
}