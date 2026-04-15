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
int sod(int n)
{
    int ans = 0;
    while(n)
    {
        ans += (n%10);
        n /= 10;
    }
    return ans;
}

void david_vivek()
{
    string s; cin >> s;
    int n = s.size();

    vi dcnt(10, 0);
    for(auto c : s) dcnt[c - '0']++;

    if (n == 1) 
    {
        cout << s << "\n";
        return;
    }

    for(int x1 = 1; x1 <= 9 * n; x1++)
    {
        string k = to_string(x1);
        int cur = x1;
        while(cur > 9)
        {
            cur = sod(cur);
            k += to_string(cur);
        }

        if(k.size() >= n) continue;

        bool ok = true;
        int p = -1; 
        rep(i, 0, (int)k.size()) 
        {
            int d = k[i] - '0';
            if(dcnt[d] > 0) 
            {
                dcnt[d]--;
                p = i;
            } 
            else 
            {
                ok = false;
                break;
            }
        }

        if(ok)
        {
            int len = n-k.size();
            int need = x1;

            if(need >= 1 && need <= 9*len) 
            {
                string x = "";
                bool f = true;
                rep(i, 0, len)
                {
                    int st = ((!i) && len > 1) ? 1 : 0;
                    bool fd = false;
                    for(int d = st; d <= 9; d++)
                    {
                        if(dcnt[d] == 0) continue;
                        int rlen = len - i - 1;
                        int rsum = need - d;
                        if(rsum >= 0 && rsum <= 9 * rlen)
                        {
                            x += char('0' + d);
                            dcnt[d]--;
                            need -= d;
                            fd = true;
                            break;
                        }
                    }
                    if(!fd) 
                    { 
                        f = false; break; 
                    }
                }

                if(f && (int)x.size() == len)
                {
                    cout << x + k << "\n";
                    return; 
                }
                
                for(char c : x) dcnt[c - '0']++;
            }
        }
        brep(i, p, 0) 
        {
            dcnt[k[i] - '0']++;
        }
    }
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