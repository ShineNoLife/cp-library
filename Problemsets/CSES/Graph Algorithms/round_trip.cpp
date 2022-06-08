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
vl adj[MAXN], ind[2*MAXN], temp;
int visited[MAXN];
bool used[2*MAXN];
bool found = false;

void dfs(int u, int cur){ 
    if(found)
        return;
    temp.pb(u);
    visited[u] = cur;
    for(int i = 0; i < adj[u].size(); i++){
        if(found)
            return;
        if(visited[adj[u][i]] > 0 && !used[ind[u][i]]){
            if(cur-visited[adj[u][i]] >= 2){
                found = true;
                ll amt = cur-visited[adj[u][i]];
                cout << amt+2 << '\n';
                cout << temp[temp.size()-1]+1 << " ";
                for(int j = temp.size()-amt-1; j < temp.size(); j++)
                    cout << temp[j]+1 << " ";
                cout << '\n';
                return;
            }
        }
        if(visited[adj[u][i]] == 0){
            used[ind[u][i]] = true;
            dfs(adj[u][i], cur+1);
            used[ind[u][i]] = false;
        }
    }
    visited[u] = -1;
    temp.pop_back();
}

void solve(){
    ll n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >>  u>> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
        ind[u].pb(i);
        ind[v].pb(i);
    }
    memset(visited, 0, sizeof(visited[0])*n);
    memset(used, false, sizeof(used[0])*m);
    for(int i = 0; i < n; i++){
        if(!visited[i])
            dfs(i, 1);
    }
    if(!found)
        cout << "IMPOSSIBLE" << '\n';
}
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}