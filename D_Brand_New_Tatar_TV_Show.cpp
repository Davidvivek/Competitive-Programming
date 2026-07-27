//"Whatever your hand finds to do, do it with all your might..."
#include <bits/stdc++.h>
using namespace std;

// ========================== CP TEMPLATE =================================
void __print(long long x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{ cerr << '{'; __print(x.first); cerr << ", "; __print(x.second); cerr << '}'; }

template <typename T>
void __print(const T &x){
    int f = 0; cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

void _print() { cerr << "]\n"; }

template <typename T, typename... V>
void _print(T t, V... v){ __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

#define disp(a){ for (int i=0; i<(int)a.size(); i++) cout << a[i] << " "; cout << "\n"; }
#define inp(a) { for (int i = 0; i < (int)a.size(); i++) cin >> (a)[i]; }
#define prt(a) cout << (a) << "\n";
#define int long long
#define rt return;
using pii  = pair<int, int>;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vpii = vector<pii>;
const long long mod = 1e9 + 7;

// ================================= SOLVE FUNCTION ======================================
void David_Vivek()
{
    int n, k;
    cin >> n >> k;
    vi a(n); inp(a);
    vi cnt(n+1, 0);
    for(auto x:a) cnt[x]++;

    bool f1, f2, f3;
    f1 = f2 = f3 = false;

    int mn = 1e6;

    for(int i=n; i>=1; i--)
    {
        if(!cnt[i]) continue;

        if(mn <= i+k) f2 = true;
        else f2 = false;

        if(f2)
        {
            f3 = true;
        }
        else
        {
            if(cnt[i]&1) f3 = false;
            else f3 = true;
        }

        if(!f3)
        {
            mn = i;
        }

        else
        {
            f1 = true;
            break;
        }
    }

    if(f1)
    {
        cout << "YES\n"; rt;
    }

    cout << "NO\n";

}

// ====== MAIN ======
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    while (t--)
    {
        David_Vivek();
    }
    return 0;
}