/*
ID: HA XUAN THIEN [haxuant1]
PROG: gift1
LANG: C++                 
*/
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

void solve(){
    ll n;
    cin >> n;
    vs v(n);
    vl ans(n);
    map<str, ll> pos;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        pos[v[i]] = i+1;
    }
    for(int i = 0; i < n; i++){
        ll c, k, amt, cur;
        str s;
        cin >> s;
        cur = pos[s]-1;
        cin >> c >> k;
        ans[cur]-=c;
        if(k != 0)
            amt = c/k;
        for(int j = 0; j < k; j++){
            str temp;
            cin >> temp;
            ll temppos = pos[temp]-1;
            ans[temppos]+=amt;
            c-=amt;
        }
        ans[cur]+=c;
    }
    for(int i = 0; i < n; i++)
        cout << v[i] << " " << ans[i] << '\n';
}

int main(){
    IOS;
    freopen("gift1.in", "r", stdin);
    freopen("gift1.out", "w", stdout);
    solve();
}