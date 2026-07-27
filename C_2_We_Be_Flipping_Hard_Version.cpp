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
    int n; cin >> n;
    vi a(n+1); 
    for(int i=1; i<=n; i++) cin >> a[i];

    int init_sum = accumulate(a.begin() , a.end(), 0LL);
    vi sign(n+1,0);
    for(int i=1; i<=n; i++) if(a[i]<0) sign[i] = 1; //neg = 1

    vi pref(n+2,0);
    vi suff(n+2,0);

    for(int i=1; i<=n; i++) pref[i] = pref[i-1] + abs(a[i]);
    for(int i=n; i>=1; i--) suff[i] = suff[i+1] + a[i];

    int mx_sum = init_sum;
    int pos = 0;

    for(int i=1; i<=n; i++)
    {
        if(!sign[i])
        {
            int cur_sum = pref[i-1] - a[i] + suff[i+1];
            if(cur_sum > mx_sum)
            {
                mx_sum = cur_sum;
                pos = i;
            }
        }
    }

    if(!pos)
    {
        prt(0);
        cout << "\n";
        return;
    }

    vi f(n+2,0);
    f[pos] = 1;
    for(int i=1; i<pos; i++)
    {
        f[i] = sign[i];
    }

    vi ans;
    for(int i=1; i<=n; i++)
    {
        if(f[i] != f[i+1]) ans.push_back(i);
    }

    prt(ans.size());
    if(ans.size())
    {
        for(int i = (int)ans.size()-2; i>=0; i--) cout << ans[i] << " ";
        cout << ans[ans.size()-1] << endl;
    }
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