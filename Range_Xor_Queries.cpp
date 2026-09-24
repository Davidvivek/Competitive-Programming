#include <bits/stdc++.h>
using namespace std;

int a[(int)2e5];
int seg[(int)8e5];

void build (int ind, int low, int high)
{
    if(low == high)
    {
        seg[ind] = a[low];
        return;
    }

    int mid = (low+high)/2;

    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);

    seg[ind] = seg[2*ind+1]^seg[2*ind+2];
}

int query (int ind, int low, int high, int l, int r)
{
    if(low>=l && high<=r)
    {
        return seg[ind];
    }

    if(high<l || low>r)
    {
        return 0;
    }

    int mid = (low+high)/2;
    int left = query(2*ind+1, low, mid, l, r);
    int right = query(2*ind+2, mid+1, high, l, r);

    return left^right;
}

int main ()
{
    int n, q;
    cin >> n >> q;
    for(int i=0; i<n; i++) cin >> a[i];

    build(0, 0, n-1);

    for(int i=0; i<q; i++)
    {
        int l, r;
        cin >> l >> r;
        l--; r--;
        int response = query(0, 0, n-1, l, r);
        cout << response << endl;
    }
}