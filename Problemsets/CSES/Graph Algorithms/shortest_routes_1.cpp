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
vl adj[MAXN], cost[MAXN];
ll dist[MAXN];
bool visited[MAXN];

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        dist[i] = INF;
        visited[i] = false;
    }
    for(int i = 0; i < m; i++){
        ll u, v, c;
        cin >> u >> v >> c;
        u--; v--;
        adj[u].pb(v);
        cost[u].pb(c);
    }
    priority_queue<pll, vpll, greater<pll>> q;
    dist[0] = 0;
    q.push(mp(0, 0));
    while(q.size()){    
        ll u = q.top().se;
        q.pop();
        if(!visited[u]){
            visited[u] = true;
            for(int i = 0; i < adj[u].size(); i++){
                if(!visited[adj[u][i]] && dist[adj[u][i]] > dist[u]+cost[u][i]){
                    dist[adj[u][i]] = dist[u]+cost[u][i];
                    q.push(mp(dist[adj[u][i]], adj[u][i]));
                }
            }
        }
    }   
    for(int i = 0; i < n; i++)
        cout << dist[i] << " ";
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