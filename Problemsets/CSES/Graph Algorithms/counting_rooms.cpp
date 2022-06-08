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

const int MAXN = 1007, dx[] = {1, -1, 0, 0}, dy[] = {0, 0, 1, -1};
ll n, m;
ll bd[MAXN][MAXN];
bool visited[MAXN][MAXN];

void dfs(int x, int y){
    visited[x][y] = true;
    for(int i = 0; i < 4; i++){
        if(x+dx[i] < 0 || x+dx[i] >= n)
            continue;
        if(y+dy[i] < 0 || y+dy[i] >= m)
            continue;
        if(!visited[x+dx[i]][y+dy[i]] && bd[x+dx[i]][y+dy[i]])
            dfs(x+dx[i], y+dy[i]);
    }
}

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        str s;
        cin >> s;
        for(int j = 0; j < m; j++){
            bd[i][j] = (s[j] == '.');
            visited[i][j] = false;
        }
    }
    ll ans = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(bd[i][j] && !visited[i][j]){
                ans++;
                dfs(i, j);
            }
        }
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