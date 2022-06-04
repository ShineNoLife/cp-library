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
    ll n, ans = 1;
    cin >> n;
    vl v(n);
    for(int i = 0; i < n; i++)
        cin >> v[i];
    map<ll, ll> cnt;
    ll l = 0, r = 0;
    cnt[v[l]]++;
    while(r < n){
        while(r < n-1 && !cnt[v[r+1]]){
            r++;
            cnt[v[r]]++;
        }
        ans = max(ans, r-l+1);
        cnt[v[l]]--;
        l++;
        if(l > r){
            r++;
            cnt[v[r]]++;
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