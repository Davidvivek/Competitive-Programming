#include <bits/stdc++.h>
using namespace std;

int query(int u, int v, int d)
{
    cout << "? " << u << " " << v << " " << d << endl;
    int res; cin >> res;
    if(res == -1) exit(0);
    return res;
}

void _()
{
    int n; cin >> n;
    int a = 1;
    int cd = 0;
    for(int i=2; i<=n; i++)
    {
        if(query(1,i, cd+1))
        {
            cd++;
            while(query(1,i, cd+1)) cd++;
            a = i;
        }
    }

    int b = 1;
    int d = cd;
    for(int i=2; i<=n; i++)
    {
        if(i==a) continue;
        if(query(a,i,d+1))
        {
            d++;
            while(query(a,i,d+1)) d++;
            b = i;
        }
    }

    cout << "! " << a << " " << b << " " << d << endl;
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        _();
    }
}