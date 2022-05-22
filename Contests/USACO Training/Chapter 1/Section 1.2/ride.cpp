/*
ID: HA XUAN THIEN [haxuant1]
PROG: ride
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
    ll c1 = 1, c2 = 1;
    str a, b;
    cin >> a >> b;
    for(int i = 0; i < a.size(); i++)
        c1*=(a[i]-'A'+1);
    for(int i = 0; i < b.size(); i++)
        c2*=(b[i]-'A'+1);
    cout << (c1%47 == c2%47 ? "GO" : "STAY") << '\n';
}

int main(){
    IOS;
    freopen("ride.in", "r", stdin);
    freopen("ride.out", "w", stdout);
    solve();
}