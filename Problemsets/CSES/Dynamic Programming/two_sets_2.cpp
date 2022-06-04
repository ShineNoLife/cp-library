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

const int MAXN = 2e5+77;
ll dp[2][MAXN];

long long binpow(long long a, long long b){
    long long ans = 1;
    while(b){
        if(b&1)
            ans = (ans*a)%MOD;
        a = (a*a)%MOD;
        b >>= 1;
    }
    return ans;
}

void solve(){
    ll n;
    cin >> n;
    memset(dp, 0, sizeof(dp));
    dp[0][0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= 200000; j++){
            dp[i%2][j] = dp[(i+1)%2][j];
            if(j >= i){
                dp[i%2][j]+=dp[(i+1)%2][j-i];
                dp[i%2][j]%=MOD;
            }
        }
    }
    ll sum = n*(n+1)/2;
    if(sum%2 != 0)
        cout << 0 << '\n';
    else
        cout << (dp[n%2][sum/2]*binpow(2, MOD-2))%MOD << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}