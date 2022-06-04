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

const int MAXN = 1e5+77;
bool dp[2][MAXN];

void solve(){
    memset(dp, false, sizeof(dp));
    ll n;
    cin >> n;
    dp[0][0] = true;
    for(int i = 1; i <= n; i++){
        ll x;
        cin >> x;
        for(int j = 0; j <= 100000; j++){
            dp[i%2][j] = (dp[i%2][j] || dp[(i+1)%2][j]);
            if(j < x)
                continue;
            dp[i%2][j] = (dp[i%2][j] || dp[(i+1)%2][j-x]);
        }
    }
    vl ans;
    for(int i = 1; i <= 100000; i++)
        if(dp[n%2][i])
            ans.pb(i);
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i] << " ";
    cout << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}