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
const char charval[] = {'D', 'U', 'R', 'L'};
ll n, m;
ll bd[MAXN][MAXN];
pll last[MAXN][MAXN];
bool visited[MAXN][MAXN];
pll pos1, pos2;
bool found = false;
vector<char> ans;

void solve(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        str s;
        cin >> s;
        for(int j = 0; j < m; j++){
            bd[i][j] = (s[j] == '.');
            visited[i][j] = false;
            if(s[j] == 'A'){
                bd[i][j] = 1;
                pos1 = mp(i, j);
            }
            if(s[j] == 'B'){
                bd[i][j] = 1;
                pos2 = mp(i, j);
            }
            last[i][j] = mp(-1, -1);
        }
    }
    queue<pll> q;
    q.push(mp(pos1.fi, pos1.se));
    while(q.size()){
        ll x = q.front().fi, y = q.front().se;
        q.pop();
        if(!visited[x][y]){
            visited[x][y] = true;
            for(int i = 0; i < 4; i++){
                if(x+dx[i] < 0 || x+dx[i] >= n)
                    continue;
                if(y+dy[i] < 0 || y+dy[i] >= m)
                    continue;
                if(!visited[x+dx[i]][y+dy[i]] && bd[x+dx[i]][y+dy[i]]){
                    last[x+dx[i]][y+dy[i]] = mp(x, y);
                    q.push(mp(x+dx[i], y+dy[i]));
                }
            }
        }
    }
    if(last[pos2.fi][pos2.se].fi == -1)
        cout << "NO" << '\n';
    ll x = pos2.fi, y = pos2.se;
    while(true){
        if(last[x][y].fi == -1)
            break;
        if(last[x][y].fi == x-1)
            ans.pb('D');
        if(last[x][y].fi == x+1)
            ans.pb('U');
        if(last[x][y].se == y-1)
            ans.pb('R');
        if(last[x][y].se == y+1)
            ans.pb('L');
        pll cur = last[x][y];
        x = cur.fi, y = cur.se;
    }
    cout << "YES" << '\n';
    cout << ans.size() << '\n';
    for(int i = ans.size()-1; i >= 0; i--)
        cout << ans[i];
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