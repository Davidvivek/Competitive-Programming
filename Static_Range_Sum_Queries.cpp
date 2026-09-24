#include <bits/stdc++.h>
using namespace std;

long long a[(long long)2e5];
long long seg[(long long)8e5];

void build(long long ind, long long low, long long high)
{
    if(low == high)
    {
        seg[ind] = a[low];
        return;
    }

    long long mid = (low+high)/2;

    build(2*ind+1, low, mid);
    build(2*ind+2, mid+1, high);

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

long long query (long long ind, long long low, long long high, long long l, long long r)
{
    if(low>=l && high<=r)
    {
        return seg[ind];
    }

    if(high<l || low>r)
    {
        return 0;
    }

    long long mid = (low+high)/2;

    long long left = query(2*ind+1, low, mid, l, r);
    long long right = query(2*ind+2, mid+1, high, l, r);

    return left+right;
}

int main ()
{
    long long n, q;
    cin >> n >> q;
    for(long long i=0; i<n; i++) cin >> a[i];

    build(0, 0, n-1);

    for(long long i=0; i<q; i++)
    {
        long long l, r;
        cin >> l >> r;
        l--; r--;
        long long response = query(0, 0, n-1, l, r);
        cout << response << endl;
    }
}