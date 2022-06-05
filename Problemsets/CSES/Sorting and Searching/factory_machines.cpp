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

const int MAXN = 2e5+777;
ll n, t, v[MAXN];

bool check(ll val){
    ll ans = 0;
    for(int i = 0; i < n; i++)
        ans+=val/v[i];
    return ans >= t;
}

void solve(){
    ll mn = INF;
    cin >> n >> t;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        mn = min(mn, v[i]);
    }
    ll l = 1, r = mn*1000000001ll;
    while(l < r){
        ll mid = (l+r)/2;
        if(check(mid))
            r = mid;
        else
            l = mid+1;
    }
    cout << r << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}