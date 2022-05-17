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
 
void recur(ll pos, ll cur, ll to){
    ll other = 6-cur-to;
    if(pos == 1)
        cout << cur << " " << to << '\n';
    else{
        recur(pos-1, cur, other);
        cout << cur << " " << to << '\n';
        recur(pos-1, other, to);
    }
}
 
void solve(){
    ll n;
    cin >> n;
    cout << (1LL << n)-1 << '\n';
    recur(n, 1, 3);
}  
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}