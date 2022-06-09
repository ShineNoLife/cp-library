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
vl temp;
deque<ll> ans;
ll visited[MAXN], deg[MAXN];
bool found = false;

void dfs(int u){
    visited[u] = 1;
    for(int i = 0; i < adj[u].size(); i++){
        if(visited[adj[u][i]] == 1)
            found = true;
        if(!visited[adj[u][i]])
            dfs(adj[u][i]);
    }
    visited[u] = 2;
    temp.pb(u);
}

void solve(){
    ll n, m;
    cin >> n >> m;
    memset(visited, 0, sizeof(visited[0])*n);
    memset(deg, 0, sizeof(deg[0])*n);
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        deg[v]++;
    }
    for(int i = 0; i < n; i++){
        if(deg[i] == 0){
            temp.clear();
            dfs(i);
            for(int j = 0; j < temp.size(); j++)
                ans.push_front(temp[j]);
        }
    }
    if(ans.size() != n || found){
        cout << "IMPOSSIBLE" << '\n';
        return;
    }
    while(ans.size()){
        cout << ans.front()+1 << " ";
        ans.pop_front();
    }
}   
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}