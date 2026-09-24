#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    int k; cin >> k;

    if(k<n || k>2*n-1)
    {
        cout << -1 << endl;
        return;
    }

    int a[n][n];
    for(int i=0; i<n; i++) for(int j=0; j<n; j++) a[i][j] = -1;
    k -= n;
    int cur=1;
    for(int i=0; i<n-k; i++)
    {
        a[i][i] = cur;
        cur++;
    }
    for(int i=n-k; i<n; i++) 
    {
        a[n-k-1][i] = cur; 
        cur++;
    }
    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++)
        {
            if(a[i][j] == -1) 
            {
                a[i][j] = cur;
                cur++;
            }
        }
    }
    

    for(int i=0; i<n; i++) 
    {
        for(int j=0; j<n; j++)
        {
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

int main ()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}