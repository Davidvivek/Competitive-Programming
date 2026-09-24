#include<bits/stdc++.h>
using namespace std;

#define int long long

int seg[4*1000005];
int lft[1000005],rgt[1000005];

void update(int ind,int low,int high,int pos)
{
    if(low==high)
    {
        seg[ind]++;
        return;
    }

    int mid = (low+high)/2;

    if(pos<=mid)
    {
        update(2*ind+1,low,mid,pos);
    }
    else
    {
        update(2*ind+2,mid+1,high,pos);
    }

    seg[ind] = seg[2*ind+1] + seg[2*ind+2];
}

int query(int ind,int low,int high,int l,int r)
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

    return query(2*ind+1,low,mid,l,r) + query(2*ind+2,mid+1,high,l,r);
}

int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n; cin >> n;
    vector<int> a(n), v;

    for(int i=0; i<n; i++)
    {
        cin >> a[i];
        v.push_back(a[i]);
    }

    sort(v.begin(),v.end());

    vector<int> rk(n);

    for(int i=0; i<n; i++)
    {
        rk[i] = lower_bound(v.begin(),v.end(),a[i]) - v.begin() + 1;
    }

    for(int i=0;i<n;i++)
    {
        if(rk[i]<n)
        {
            lft[i] = query(0,1,n,rk[i]+1,n);
        }

        update(0,1,n,rk[i]);
    }

    memset(seg,0,sizeof(seg));

    for(int i=n-1; i>=0; i--)
    {
        if(rk[i]>1)
        {
            rgt[i] = query(0,1,n,1,rk[i]-1);
        }

        update(0,1,n,rk[i]);
    }

    int ans=0;

    for(int i=0; i<n; i++)
    {
        ans += lft[i]*rgt[i];
    }

    cout<< ans << endl;
}