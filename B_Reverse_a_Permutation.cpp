#include <bits/stdc++.h>
using namespace std;

int main ()
{
    int t; cin >> t;
    while(t--)
    {
        int n; cin >> n;
        vector<int> a(n); 
        for(int i=0; i<n; i++) cin >> a[i];
        int idx=-1;
        int el=-1;
        for(int i=0; i<n; i++)
        {
            if(n-i != a[i])
            {
                el = n-i;
                idx = i;
                break;
            }
        }
        int idx2=-1;
        for(int i=idx; i<n; i++)
        {
            if(a[i]==el) 
            {
                idx2 = i;
                break;
            }
        }
        reverse(a.begin()+idx, a.begin()+idx2+1);
        for(int i=0; i<n; i++) cout << a[i] << " ";
        cout << endl;
        
    }
}