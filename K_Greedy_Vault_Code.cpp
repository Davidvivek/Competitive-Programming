#include <bits/stdc++.h>
using namespace std;

#define int long long
#define LOCAL // comment out

#ifdef LOCAL
#define dbg(...) debug_out(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...) 0
#endif



template<typename T> ostream& operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(size_t i = 0; i < v.size(); i++) {
        os << v[i]; if(i != v.size()-1) os << ", ";
    }
    return os << "]";
}


template<typename T> ostream& operator<<(ostream &os, const set<T> &s) {
    os << "{";
    size_t i=0; for(auto &x:s){ os << x; if(i!=s.size()-1) os << ", "; i++; }
    return os << "}";
}

template<typename K, typename V> ostream& operator<<(ostream &os, const map<K,V> &m) {
    os << "{";
    size_t i=0;
    for(const auto &pair : m){
        os << "(" << pair.first << ":" << pair.second << ")";
        if(i != m.size()-1) os << ", ";
        i++;
    }
    return os << "}";
}

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A,B> &p) {
    return os << "(" << p.first << "," << p.second << ")";
}

template<typename T, typename Hash, typename Eq, typename Alloc>
ostream& operator<<(ostream &os, const unordered_set<T, Hash, Eq, Alloc> &s) {
    os << "{";
    size_t i = 0;
    for (const auto &x : s) {
        os << x;
        if (i != s.size() - 1) os << ", ";
        i++;
    }
    return os << "}";
}

template<typename K, typename V, typename Hash, typename Eq, typename Alloc>
ostream& operator<<(ostream &os, const unordered_map<K,V,Hash,Eq,Alloc> &m) {
    os << "{";
    size_t i = 0;
    for (const auto &p : m) {
        os << "(" << p.first << ":" << p.second << ")";
        if (i != m.size() - 1) os << ", ";
        i++;
    }
    return os << "}";
}

template<typename T>
void debug_out(const char* name, T&& arg) { cerr << name << " = " << arg << "\n"; }

template<typename T, typename... Args>
void debug_out(const char* names, T&& arg, Args&&... args) {
    const char* comma = strchr(names, ',');
    cerr.write(names, comma - names) << " = " << arg << " | ";
    debug_out(comma+1, args...);
}

struct VectorHash {
    size_t operator()(const vector<int>& v) const {
        size_t hash = 0;
        for (int x : v) {
            hash = hash * 31 + x;
        }
        return hash;
    }
};


struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }
    //mp.reserve(1 << 20);
    // mp.max_load_factor(0.25); to trade memory for speed


    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM =
            chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};

int gcd(int a, int b) { a= abs(a), b=abs(b);return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return (a / gcd(a, b)) * b; }



// main code
//
//


int32_t main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 1;
    // cin >> t;  

    while (t--)
    {
       string l, r, k;
       cin>>l>>r>>k;
       int ln=stol(l), rn=stol(r), kn=stol(k);
       int ksum=kn;

    //    dbg(ln, rn, kn, ksum);

    //    int minsize=(ksum+ 9LL - 1LL)/9LL; 
       int kcnt=(ksum/9LL);
       int left=ksum -(kcnt*9LL);

    //    dbg(minsize, kcnt, left);
       string minans="";
       minans.append(kcnt, '9');
    //    dbg(minans);
       minans = (char)('0' + left) + minans;
    //    dbg(minans);
       if(stol(minans) > rn || stol(minans)>ln)
       {
            cout<<-1<<endl;
            continue;
       }

       if(l.size()<=minans.size())
       {
            cout<<stoi(minans)<<endl;
            continue;
       }


       int req0s=l.size()-minans.size();
       minans[0]=(minans[0]-1); //reduce by one and carryforward it to the most sig digit

       for(int j=0;j<req0s-1;j++) minans='0'+minans;
       minans= '1' + minans;

       cout<<stoi(minans)<<endl;
    }

    return 0;
}
