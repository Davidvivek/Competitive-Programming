#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n; cin >> n;
    vector<int> a(n);
    for(auto &x:a) cin >> x;

    int cnt1 = 0;
    for(auto x:a) if(x == 1) cnt1++;
    int cnt0 = n-cnt1;

    if(cnt1 >= cnt0) cout << "Bessie\n";
    else cout << "Elsie\n";
    return;
}

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}