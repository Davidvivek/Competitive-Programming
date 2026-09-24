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
    void __print(const char *x) { cerr << '\"' << x << '\"'; }
    void __print(const string &x) { cerr << '\"' << x << '\"'; }
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

    // ====== SOLVE FUNCTION ======
    struct Node
    {
        int open;
        int close;
        int full;
    };

    string s;
    Node seg[(int)4e6 + 5];

    Node merge(Node left, Node right)
    {
        Node ans;

        int match = min(left.open, right.close);

        ans.full = left.full + right.full + match;
        ans.open = left.open + right.open - match;
        ans.close = left.close + right.close - match;

        return ans;
    }

    void build(int ind, int low, int high)
    {
        if(low == high)
        {
            if(s[low] == '(')
            {
                seg[ind].open = 1;
                seg[ind].close = 0;
            }
            else
            {
                seg[ind].open = 0;
                seg[ind].close = 1;
            }

            seg[ind].full = 0;
            return;
        }

        int mid = (low + high) / 2;

        build(2*ind+1, low, mid);
        build(2*ind+2, mid+1, high);

        seg[ind] = merge(seg[2*ind+1], seg[2*ind+2]);
    }

    Node query(int ind, int low, int high, int l, int r)
    {
        if(low >= l && high <= r)
        {
            return seg[ind];
        }

        if(high < l || low > r)
        {
            return {0, 0, 0};
        }

        int mid = (low + high) / 2;

        Node left = query(2*ind+1, low, mid, l, r);
        Node right = query(2*ind+2, mid+1, high, l, r);

        return merge(left, right);
    }

    void david_vivek()
    {
        cin >> s;

        int n = s.size();

        build(0, 0, n-1);

        int q;
        cin >> q;

        while(q--)
        {
            int l, r;
            cin >> l >> r;

            l--;
            r--;

            Node ans = query(0, 0, n-1, l, r);

            cout << 2*ans.full << "\n";
        }
    }
    // ====== MAIN ======
    int32_t main()
    {
        ios::sync_with_stdio(false);
        cin.tie(nullptr);

        int t = 1;
        // cin >> t;
        //sieve();
        while (t--)
        {
            david_vivek();
        }

        // cerr << "Time : " << 1000 * ((double)clock()) / CLOCKS_PER_SEC << " ms\n";
        return 0;
    }