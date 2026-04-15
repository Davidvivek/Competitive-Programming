//"Whatever your hand finds to do, do it with all your might..."
#include <bits/stdc++.h>
using namespace std;

// ====== DEBUG PRINTERS ======
void __print(int x) { cerr << x; }
void __print(long x) { cerr << x; }
void __print(long long x) { cerr << x; }
void __print(unsigned x) { cerr << x; }
void __print(unsigned long x) { cerr << x; }
void __print(unsigned long long x) { cerr << x; }
void __print(float x) { cerr << x; }
void __print(double x) { cerr << x; }
void __print(long double x) { cerr << x; }
void __print(char x) { cerr << '\'' << x << '\''; }
void __print(const char *x) { cerr << '"' << x << '"'; }
void __print(const string &x) { cerr << '"' << x << '"'; }
void __print(bool x) { cerr << (x ? "true" : "false"); }

template <typename T, typename V>
void __print(const pair<T, V> &x)
{
    cerr << '{';
    __print(x.first);
    cerr << ',';
    __print(x.second);
    cerr << '}';
}


template <typename T>
void __print(const T &x)
{
    int f = 0;
    cerr << '{';
    for (auto &i : x)
        cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}

template <typename T>
void __print(const vector<vector<T>> &mat)
{
    cerr << "\n";
    for (auto &row : mat)
    {
        for (auto &val : row)
        {
            cerr << val << " ";
        }
        cerr << "\n";
    }
}

void _print()
{
    cerr << "]\n";
}

template <typename T, typename... V>
void _print(T t, V... v)
{
    __print(t);
    if (sizeof...(v)) cerr << ", ";
    _print(v...);
}

#ifndef ONLINE_JUDGE
#define TxtIO \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);

#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

// ====== VITAL FUNCTIONS ======
int bepow(int a, int n)
{
    if (n == 0) return 1;
    int res = bepow(a, n / 2);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}

// ====== TYPE ALIASES ======
#define int long long
using pii  = pair<int, int>;
using ld   = long double;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vpii = vector<pii>;
using mii  = map<int, int>;
using sii  = set<int>;

// ====== COMMON MACROS ======
#define ff first
#define ss second
#define pb push_back
#define mp make_pair
#define rt return;
#define py cout << "YES\n";
#define pm cout << "-1\n";
#define pn cout << "NO\n";
#define nl cout << "\n";

// ====== LOOP MACROS ======
#define rep(i, a, b) for (int i = a; i < b; i++)
#define brep(i, a, b) for (int i = a; i >= b; i--)

// ====== CONTAINER HELPERS ======
#define disp(a) { for (int i = 0; i < (int)a.size(); i++) cout << a[i] << " "; cout << "\n"; }
#define inp(a)  { for (int i = 0; i < (int)a.size(); i++) cin >> (a)[i]; }
#define all(v)  (v).begin(), (v).end()
#define rll(v)  (v).rbegin(), (v).rend()
#define fsort(v) sort(all(v))
#define rsort(v) sort(rll(v))

#define prt(a) cout << (a) << "\n";

#define minel(a) (*min_element(all(a)))
#define maxel(a) (*max_element(all(a)))
#define mini(a)  (min_element(all(a)) - (a).begin())
#define maxi(a)  (max_element(all(a)) - (a).begin())
#define lowb(a,x) (lower_bound(all(a),x)-a.begin())
#define uppb(a,x) (upper_bound(all(a),x)-a.begin())

// ====== MOD CONSTANT ======
const long long mod = 1e9 + 7;

// ====== SIEVE and PRIME FACTORS ======
const int N = 1e3;
int spf[N + 1];
void sieve()
{
    for (int i = 2; i <= N; i++) spf[i] = i;
    for (int i = 2; i * i <= N; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= N; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

vector<int> gp(int n)
{
    vector<int> res;
    while (n != 1)
    {
        res.push_back(spf[n]);
        n /= spf[n];
    }
    return res;
}

// ====== SOLVE FUNCTION ======
void bfs(int src, vvi& adjg, vi& comp, int cid)
{
    queue<int> q;
    q.push(src);
    comp[src] = cid;
    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        for(auto v:adjg[u])
        {
            if(comp[v] == -1)
            {
                comp[v] = cid;
                q.push(v);
            }
        }
    }
}
void david_vivek()
{
    int n, m1, m2;
    cin >> n >> m1 >> m2;
    vvi adjf(n), adjg(n);
    vpii edges_f;
    rep(i,0,m1)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjf[u].pb(v);
        adjf[v].pb(u);
        edges_f.pb({u,v});
    }
    rep(i,0,m2)
    {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adjg[u].pb(v);
        adjg[v].pb(u);
    }

    vi compg(n,-1);
    int comp_no_g=0;
    rep(i,0,n)
    {
        if(compg[i] == -1)
        {
            bfs(i,adjg,compg,comp_no_g++);
        }
    }

    int ops=0;
    vvi new_adjf(n);
    for(auto e:edges_f)
    {
        int u = e.ff, v = e.ss;
        if(compg[u] == compg[v])
        {
            new_adjf[u].pb(v);
            new_adjf[v].pb(u);
        }
        else ops++;
    }
    adjf = new_adjf;

    vi vis(n,0);
    int con_f=0;
    rep(i,0,n)
    {
        if(!vis[i])
        {
            con_f++;
            queue<int> q;
            q.push(i);
            vis[i] = 1;
            while(!q.empty())
            {
                int u = q.front(); 
                q.pop();
                for(auto v: adjf[u])
                {
                    if(!vis[v])
                    {
                        vis[v] = 1;
                        q.push(v);
                    }
                }
            }
        }
    }

    int ans = ops + con_f - comp_no_g;
    prt(ans);
    
}

// ====== MAIN ======
int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    cin >> t;
    //sieve();
    while (t--)
    {
        david_vivek();
    }

    // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";
    return 0;
}