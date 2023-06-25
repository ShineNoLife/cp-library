#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
using ull = unsigned long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using str = string;
using ld = long double;
using db = double;

///--------------------------------

#define           F   first
#define           S   second
#define          pb   push_back
#define       sz(x)   (int)((x).size())
#define      all(x)   (x).begin(), (x).end()
#define     rall(x)   (x).rbegin(), (x).rend()
#define   mem(f, x)   memset(f, x, sizeof(f))

template<class T> bool maximize(T &a, const T &b){ return (a < b ? a = b, 1 : 0); }
template<class T> bool minimize(T &a, const T &b){ return (a > b ? a = b, 1 : 0); }

///--------------------------------

#ifdef LOCAL
    #include "deb/debug.h"
#else
    #define debug(...) 2807
#endif

///--------------------------------

#define PROBLEM "test"

const int MOD = 1e9 + 7; // 998244353;
const ll INF = 1e18;
const ld eps = 1e-9;
const ld PI = acos(-1);
const int dx[4]{0, 1, 0, -1}, dy[4]{1, 0, -1, 0}; // R D L U
const int ddx[4]{-1, 1, 1, -1}, ddy[4]{1, 1, -1, -1}; // UR DR DL UL

///--------------------------------

void precalc();
void solve();

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    
    if (fopen(PROBLEM".inp", "r")) {
        freopen(PROBLEM".inp", "r", stdin);
        freopen(PROBLEM".out", "w", stdout);
    }
    
    constexpr bool MULTI_TEST = 0;

    int t = 1;
    if (MULTI_TEST) cin >> t;
    while (t--)
        solve();

    // cerr << setprecision(3) << fixed;
    // cerr << "[" << 1.0 * clock() / CLOCKS_PER_SEC << "s]  ";
}

///--------------------[PROBLEM SOLUTION]--------------------///

void solve() {
    
}   
