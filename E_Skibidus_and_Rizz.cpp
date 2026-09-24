#include <bits/stdc++.h>
using namespace std;

void David_Vivek()
{
    int n, m, k;
    cin >> n >> m >> k;

    if(k < abs(m-n) or k > max(m,n))
    {
        cout << -1 << endl;
        return;
    }

    pair<int,int> use1 = {n,0}, use2 = {m,1};
    if(m>n) swap(use1, use2);
    for(int i=0; i<k; i++)
    {
        cout << use1.second;
        use1.first--;
    }
    while(use2.first > 0)
    {
        cout << use2.second;
        use2.first--;
        swap(use1, use2);
    }
    while(use1.first > 0)
    {
        cout << use1.second;
        use1.first--;
    }
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while(t--)
    {
        David_Vivek();
    }
}