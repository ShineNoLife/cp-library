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

multiset<ll> lower, upper;
multiset<ll>::iterator it;

void equalize(ll sz){
    while(lower.size() < sz){
        it = upper.begin();
        ll val = *it;
        lower.insert(val);
        upper.erase(upper.find(val));
    }
    while(lower.size() > sz){
        it = lower.end();
        it--;
        ll val = *it;
        lower.erase(lower.find(val));
        upper.insert(val);
    }
}

void solve(){
    ll n, k;
    cin >> n >> k;
    vl v(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    for(int i = 1; i <= k; i++)
        upper.insert(v[i]);
    equalize((k+1)/2);
    it = lower.end();
    it--;
    cout << *it << " ";
    for(int i = k+1; i <= n; i++){
        it = lower.end();
        it--;
        if(*it < v[i])
            upper.insert(v[i]);
        else
            lower.insert(v[i]);
        it = lower.end();
        it--;
        if(*it < v[i-k])
            upper.erase(upper.find(v[i-k]));
        else
            lower.erase(lower.find(v[i-k]));
        equalize((k+1)/2);
        it = lower.end();
        it--;
        cout << *it << " ";
    }
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