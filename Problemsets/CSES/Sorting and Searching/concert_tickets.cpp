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

//const int MOD = 1e9+7;
const int MOD = 998244353;
const ll INF = 1e18;

void solve(){
    ll n, m;
    cin >> n >> m;
    vl v(n);
    multiset<ll> st;
    multiset<ll>::iterator it;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        st.insert(v[i]);
    }
    sort(all(v));
    for(int i = 0; i < m; i++){
        ll x;
        cin >> x;
        it = st.up_b(x);
        if(it == st.begin())
            cout << -1 << '\n';
        else{
            cout << *(--it) << '\n';
            st.erase(it);
        }
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