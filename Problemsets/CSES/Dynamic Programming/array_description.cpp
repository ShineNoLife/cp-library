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

const int MAXN = 1e5+777;
const int MAXK = 107;
ll dp[MAXN][MAXK];

void solve(){
    ll n, m;
    cin >> n >> m;
    vl v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m+1; j++){
            dp[i][j] = 0;
        }
    }
    if(v[1] == 0){
        for(int j = 1; j <= m; j++)
            dp[1][j] = 1;
    }
    else
        dp[1][v[1]] = 1;
    for(int i = 2; i <= n; i++){
        if(v[i] != 0){
            dp[i][v[i]]+=dp[i-1][v[i]-1];
            dp[i][v[i]]%=MOD;
            dp[i][v[i]]+=dp[i-1][v[i]];
            dp[i][v[i]]%=MOD;
            dp[i][v[i]]+=dp[i-1][v[i]+1];
            dp[i][v[i]]%=MOD;
            continue;
        }
        for(int j = 1; j <= m; j++){
            dp[i][j]+=dp[i-1][j-1];
            dp[i][j]%=MOD;
            dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
            dp[i][j]+=dp[i-1][j+1];
            dp[i][j]%=MOD;
        }
    }
    ll ans = 0;
    for(int j = 1; j <= m; j++){
        ans+=dp[n][j];
        ans%=MOD;
    }
    cout << ans << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}