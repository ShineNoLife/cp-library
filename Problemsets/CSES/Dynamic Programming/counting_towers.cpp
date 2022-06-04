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

const int MAXN = 1e6+777;
ll dp[MAXN][2];

void solve(){
    ll n;
    cin >> n;
    cout << (dp[n][0]+dp[n][1])%MOD << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    dp[0][0] = 0;
    dp[0][1] = 1;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i = 2; i <= 1000000; i++){
        dp[i][0] = (dp[i][0]+dp[i-1][1])%MOD;
        dp[i][0] = (dp[i][0]+dp[i-1][0]*4)%MOD;
        dp[i][1] = (dp[i][1]+dp[i-1][0])%MOD;
        dp[i][1] = (dp[i][1]+2*dp[i-1][1])%MOD;
    }
    int t;
    cin >> t;
    while(t--)
        solve();
}