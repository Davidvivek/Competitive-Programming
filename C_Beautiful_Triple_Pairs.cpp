#include <bits/stdc++.h>
using namespace std;

using ll = long long;

void david_vivek()
{
    int n;
    cin >> n;

    vector<int> a(n);
    for (int &x : a) cin >> x;

    map<pair<int,int>, ll> c01, c02, c12;
    map<tuple<int,int,int>, ll> full;

    ll ans = 0;

    for (int i = 0; i + 2 < n; i++)
    {
        int x = a[i], y = a[i+1], z = a[i+2];

        ans += c12[{y, z}];
        ans += c02[{x, z}];
        ans += c01[{x, y}];

        ans -= 3 * full[{x, y, z}];

        c12[{y, z}]++;
        c02[{x, z}]++;
        c01[{x, y}]++;
        full[{x, y, z}]++;
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
        david_vivek();

    return 0;
}
