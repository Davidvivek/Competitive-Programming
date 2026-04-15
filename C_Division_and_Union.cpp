//"Whatever your hand finds to do, do it with all your might..."
#include <bits/stdc++.h>
using namespace std;

// ========================== CP TEMPLATE =================================
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
{ cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}'; }
template <typename T>
void __print(const T &x){
    int f = 0; cerr << '{';
    for (auto &i : x) cerr << (f++ ? "," : ""), __print(i);
    cerr << "}";
}
template <typename T>
void __print(const vector<vector<T>> &mat)
{
    cerr << "\n";
    for (auto &row : mat)
    {
        for (auto &val : row) cerr << val << " ";
        cerr << "\n";
    }
}
void _print() { cerr << "]\n"; }
template <typename T, typename... V>
void _print(T t, V... v){ __print(t); if (sizeof...(v)) cerr << ", "; _print(v...); }

#ifndef ONLINE_JUDGE
#define TxtIO \
    freopen("input.txt", "r", stdin); \
    freopen("output.txt", "w", stdout);
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

int bepow(int a, int n)
{
    if (n == 0) return 1;
    int res = bepow(a, n / 2);
    if (n % 2)
        return res * res * a;
    else
        return res * res;
}
#define disp(a){ for (int i=0; i<(int)a.size(); i++) cout << a[i] << " "; cout << "\n"; }
#define inp(a) { for (int i = 0; i < (int)a.size(); i++) cin >> (a)[i]; }
#define all(v) (v).begin(), (v).end()
#define rll(v) (v).rbegin(), (v).rend()
#define prt(a) cout << (a) << "\n";
const long long mod = 1e9 + 7;
#define int long long
using pii  = pair<int, int>;
using vi   = vector<int>;
using vvi  = vector<vi>;
using vpii = vector<pii>;
#define rt return;
// =================================END OF CP TEMPLATE ===================================
// ================================= SOLVE FUNCTION ======================================
void david_vivek()
{
    
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
        david_vivek();
    }
    return 0;
}