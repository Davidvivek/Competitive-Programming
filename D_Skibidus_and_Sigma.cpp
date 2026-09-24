#include <bits/stdc++.h>
using namespace std;

#define int long long

void David_Vivek()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<int> scores, sums;
    for(int i=0; i<n; i++)
    {
        int ind_score = 0;
        int ind_sum = 0;
        for(int j=0; j<m; j++)
        {
            cin >> a[i][j];
            ind_score += ((m-j)*a[i][j]);
            ind_sum += (a[i][j]);
        }
        scores.push_back(ind_score);
        sums.push_back(ind_sum);
    }

    int ans = accumulate(scores.begin(), scores.end(), 0LL);
    sort(sums.begin(), sums.end());
    for(int i=0; i<n; i++)
    {
        ans += (sums[i]*i*m);
    }

    cout << ans << endl;
}

int32_t main()
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