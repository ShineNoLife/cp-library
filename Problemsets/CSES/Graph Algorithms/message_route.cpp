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
vl adj[MAXN];
ll last[MAXN];
bool visited[MAXN];

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    queue<ll> q;
    q.push(0);
    for(int i = 0; i < n; i++)
        last[i] = -1;
    while(q.size()){
        ll u = q.front();
        q.pop();
        if(!visited[u]){
            visited[u] = true;
            for(int i = 0; i < adj[u].size(); i++){
                if(!visited[adj[u][i]] && last[adj[u][i]] == -1){
                    last[adj[u][i]] = u;
                    q.push(adj[u][i]);
                }
            }
        }
    }
    if(!visited[n-1]){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    vl ans;
    ll cur = n-1;
    while(cur != -1){
        ans.pb(cur);
        cur = last[cur];
    }
    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i]+1 << " ";
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