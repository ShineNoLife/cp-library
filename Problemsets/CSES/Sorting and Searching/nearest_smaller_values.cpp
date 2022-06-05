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

void solve(){
    ll n;
    cin >> n;
    vl v(n), ans(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    stack<pll> stk;
    for(int i = 0; i < n; i++){
        while(stk.size() && stk.top().fi >= v[i])
            stk.pop();
        if(stk.size())
            ans[i] = stk.top().se;
        else
            ans[i] = -1;
        stk.push(mp(v[i], i));
    }
    for(int i = 0; i < n; i++)
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