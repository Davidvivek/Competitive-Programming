#include <bits/stdc++.h>
using namespace std;

int a[200005];
int seg[4*200005];

void build (int ind, int low, int high)
{
    if(low == high)
    {
        seg[ind] = a[low];
        return;
    }
    int mid = (low + high)/2;
    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);

    seg[ind] = min(seg[2*ind+1] , seg[2*ind+2]);
}

int query (int ind, int low, int high, int l, int r)
{
    if(low>=l && high<=r)
    {
        return seg[ind];
    }

    if(high<l || low>r)
    {
        return INT_MAX;
    }

    int mid = (low+high)/2;
    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);
    return min(left, right);
}

int main ()
{
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];

    build(0, 0, n-1);

    for(int i=0; i<q; i++)
    {
        int a, b;
        cin >> a >> b;
        a--; b--;
        cout << query(0, 0, n-1, a, b) << endl;
    }
}