#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;
    vector<int> f;
    for(int i=0; i<n; i++) if(a[i] != i+1) f.push_back(a[i]);
    for(int i=0; i<(int)f.size()-1; i++)
    {
        if(f[i]<f[i+1])
        {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";
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