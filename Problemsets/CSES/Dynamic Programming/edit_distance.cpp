#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using str = string;
using db = long double;
 
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdb = pair<db, db>;
 
using vi = vector<int>;
using vl = vector<ll>;
using vdb = vector<db>;
using vb = vector<bool>;
using vs = vector<str>;
using vpii = vector<pii>;
using vpll = vector<pll>;
using vpdb = vector<pdb>;
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)

//pairs
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second

//vectors
#define pb push_back
#define pf push_front
#define low_b lower_bound
#define up_b upper_bound

const int MOD = 1e9+7;
//const int MOD = 998244353;
const ll INF = 1e18;

const int MAXN = 5007;
ll dp[MAXN][MAXN];

void solve(){
    str s, t;
    cin >> s >> t;
    ll n = sz(s), m = sz(t);
    s+='*'; t+='*';
    s = '*'+s; t = '*'+t;
    for(int i = 0; i <= n+1; i++){
        for(int j = 0; j <= m+1; j++){
            dp[i][j] = INF;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= m+1; i++)
        dp[0][i] = i;
    for(int i = 1; i <= n+1; i++)
        dp[i][0] = i;
    for(int i = 1; i <= n+1; i++){
        for(int j = 1; j <= m+1; j++){
            dp[i][j] = max({dp[i][j], dp[i-1][j], dp[i][j-1]});
            if(s[i] == t[j])
                dp[i][j] = min(dp[i][j], dp[i-1][j-1]);
            dp[i][j] = min({dp[i][j], dp[i-1][j-1]+1, dp[i-1][j]+1, dp[i][j-1]+1});
        }
    }
    cout << dp[n][m] << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}