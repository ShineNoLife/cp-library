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
ll dp[MAXN][MAXN][2];

void solve(){
    ll n;
    cin >> n;
    vl v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
        dp[i][i][0] = v[i];
        dp[i][i][1] = 0;
    }
    for(int len = 2; len <= n; len++){
        for(int i = 0; i < n-len+1; i++){
            int j = i+len-1;
            dp[i][j][0] = max(dp[i+1][j][1]+v[i], dp[i][j-1][1]+v[j]);            
            dp[i][j][1] = min(dp[i+1][j][0], dp[i][j-1][0]);
        }
    }
    cout << dp[0][n-1][0] << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}