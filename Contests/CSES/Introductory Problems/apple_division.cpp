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
#define sz(x) (int)(x.size())
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
 
const int MOD = 1e9+7;
//const int MOD = 998244353;
const ll INF = 1e18;
 
ll n, ans = INF;
ll v[30], cur[30];
 
void recur(ll pos){
    if(pos == n){
        ll curs = 0, others = 0;
        for(int i = 0; i < n; i++){
            if(cur[i])
                curs+=v[i];
            else
                others+=v[i];
        }
        ans = min(ans, abs(curs-others));
        return;
    }
    cur[pos] = 0;
    recur(pos+1);
    cur[pos] = 1;
    recur(pos+1);
}
 
void solve(){
    cin >> n;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    recur(0);
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