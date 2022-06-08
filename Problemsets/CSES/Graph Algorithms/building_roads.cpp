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
ll par[MAXN], rnk[MAXN];

ll root(int u){
    if(par[u] == u)
        return u;
    par[u] = root(par[u]);
    return par[u];
}

void unite(int x, int y){
    int p1 = root(x), p2 = root(y);
    if(rnk[p1] > rnk[p2]){
        par[p2] = p1;
    }
    else{
        par[p1] = p2;
        rnk[p2] = max(rnk[p2], rnk[p1]+1);
    }
}

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        par[i] = i;
        rnk[i] = 1;
    }
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        if(root(u) != root(v))
            unite(u, v);
    }
    vpll ans;
    for(int i = 1; i < n; i++){
        if(root(0) != root(i)){
            unite(0, i);
            ans.pb(mp(0, i));
        }
    }
    cout << ans.size() << '\n';
    for(int i = 0; i < ans.size(); i++)
        cout << ans[i].fi+1 << " " << ans[i].se+1 << '\n';
}
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}