#include<bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace __gnu_pbds;
using namespace chrono;

#define     fastasfuckboi ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0)
#define     test int t;cin>>t;while(t--)
#define     REP(i,n) for(int i=0; i<n;i++)
#define     rep(i,a,b) for(int i=a;i<b;i++)
#define     mod 1000000007
#define     mod2 998244353
#define     int long long
#define     ll long long
#define     pb push_back
#define     mp make_pair
#define     ii pair<int,int>
#define     vi vector<int>
#define     f first
#define     s second
#define     INF 1000000000
#define     mem(a,b) memset(a,b,sizeof(a))
#define     all(r) r.begin(),r.end()
#define     endl '\n'

template<class T> 
using ordered_set =tree<T, null_type, less<T>, rb_tree_tag,tree_order_statistics_node_update> ;
template<typename T,typename T1>T amax(T &a,T1 b){if(b>a)a=b;return a;}
template<typename T,typename T1>T amin(T &a,T1 b){if(b<a)a=b;return a;}

/*
           ___         _      __   __    ____                                     
          / _ \_    __(_)__ _/ /  / /_  / __/_ _____  _______ __ _  ___ _______ __
         / // / |/|/ / / _ `/ _ \/ __/ _\ \/ // / _ \/ __/ -_)  ' \/ _ `/ __/ // /
        /____/|__,__/_/\_, /_//_/\__/ /___/\_,_/ .__/_/  \__/_/_/_/\_,_/\__/\_, / 
                      /___/                   /_/                          /___/  

*/

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

namespace number_theory{
    int powersimple(int a, int b){
        int res=1;
        while(b>0){
            if(b&1) { res=(res*a); b--; } a=(a*a); b>>=1; }
        return res;
    }
    int ncr(int n,int k) {
        int ans=1;
        if(k>n-k) { k=n-k; } for(int i=1;i<=k;i++) { ans*=(n-i+1),ans/=i; }
        return ans;
    }
    int power(int r,int y,int p) {
        int res = 1; r = r % p;
        while (y > 0) { if (y & 1) res = (res * r) % p;
            y = y >> 1; r = (r * r) % p; }
        return res;
    }
    int modInverse(int n, int p) {
        return power(n, p - 2, p);
    }
    int ncrModPFermat(int n,int r, int p) {
        if (r == 0) return 1;
        int fac[n + 1]; fac[0] = 1;
        for (int i = 1; i <= n; i++) fac[i] = (fac[i - 1] * i) % p;
        return (fac[n] * modInverse(fac[r], p) % p * modInverse(fac[n - r], p) % p) % p;
    }
    int gcd(int a, int b) {
        return (b==0)? a: gcd(b,a%b);
    }
}
using namespace number_theory;

// https://codeforces.com/blog/entry/62393
struct custom_hash {
    static uint64_t splitmix64(uint64_t r) {
        // http://xorshift.di.unimi.it/splitmix64.c
        r += 0x9e3779b97f4a7c15;
        r = (r ^ (r >> 30)) * 0xbf58476d1ce4e5b9;
        r = (r ^ (r >> 27)) * 0x94d049bb133111eb;
        return r ^ (r >> 31);
    }

    size_t operator()(uint64_t r) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(r + FIXED_RANDOM);
    }
};

void solve(){
    string s; 
    vi bits(12,0);
    while(cin>>s){
        assert(s.size()==12);
        REP(i,12){
            if(s[i]=='1') bits[i]++;
            else bits[i]--;
        }
    }
    int num1=0, num2=0;
    REP(i,12){
        if(bits[i]>0) num1+= (1<<(12-i-1));
        else if(bits[i]<0) num2+= (1<<(12-i-1));
        else{
            num1+=(1<<(12-i-1));
            num2+=(1<<(12-i-1));
        }
    }
    cout<<num1*num2;
}

signed main()
{
    fastasfuckboi;
    int t=1;
    // cin>>t;
    while(t-->0){
        solve();
    }
    cerr<<"\n\nTime: "<<(float)clock()/CLOCKS_PER_SEC<<" secs";
    return 0;
}
