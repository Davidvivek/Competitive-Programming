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
int lcm(int a, int b)
{
    return (a*b)/__gcd(a,b);
}
void david_vivek()
{
    int a,b,c,m;
    cin >> a >> b >> c >> m;

    int x = m/a;
    int y = m/b;
    int z = m/c;

    int d = lcm(a,b);
    int e = lcm(a,c);
    int f = lcm(b,c);
    int g = lcm(d,c);
    int p = m/d;
    int q = m/e;
    int r = m/f;
    int s = m/g;

    int u = x - p - q + s;
    int v = y - p - r + s;
    int w = z - q - r + s;
    int i = p - s;
    int j = q - s;
    int k = r - s;

    int A = 6*u + 3*i + 3*j + 2*s;
    int B = 6*v + 3*i + 3*k + 2*s;
    int C = 6*w + 3*j + 3*k + 2*s;

    cout << A << " " << B << " " << C << "\n";
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