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
    // ====== Optional Local File I/O (use only locally) ======
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
        if(n == 0) return 1;

        int res = bepow(a, n / 2);

        if(n % 2) // if odd power
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

    // ====== SOLVE FUNCTION ======
    void david_vivek()
    {
        int n; cin >> n;
        vi a(n); inp(a);
        int l=0, r=n-1; int c1=-1, c2=-1;
        while(l<r)
        {
            if(a[l] == a[r]) {l++; r--;}
            else{c1 = a[l]; c2 = a[r]; break;}
        }
        if(c1==-1 ){py; return;}
        vi b1;
        rep(i,0,n){if(a[i] != c1) b1.push_back(a[i]);}
        vi k1 = b1;
        reverse(all(k1));
        vi b2;
        rep(i,0,n){if(a[i] != c2) b2.push_back(a[i]);}
        vi k2 = b2;
        reverse(all(k2));
        if(k1==b1 || k2==b2){py;} else{pn;}
        
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

        // Debug runtime locally
        // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";

        return 0;
    }