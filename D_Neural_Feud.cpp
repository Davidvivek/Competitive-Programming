#include <bits/stdc++.h>
using namespace std;

void solve()
{
    int n; cin >> n;

    if(n==1)
    {
        cout << "walk";
    }

    if(n==2)
    {
        cout << "No";
    }

    if(n==3)
    {
        cout << "No";
    }

    if(n==4)
    {
        cout << "No";
    }

    if(n==5)    
    {
        cout << "Yes";   
    }

    if(n==6)
    {
        cout << "Yes"; 
    }

    if(n==7)
    {
        cout << "backwards";
    }

    if(n==8)
    {
        cout << "1";
    }
    cout << endl;
}

int main ()
{
    int t=1;
    while(t--)
    {
        solve();
    }
}