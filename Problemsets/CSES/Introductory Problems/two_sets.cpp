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
    ll amt = n*(n+1)/2;
    if(amt%2 != 0){
        cout << "NO" << '\n';
        return;
    }
    amt/=2;
    vl ans1, ans2;
    for(int i = n; i >= 1; i--){
        if(amt >= i){
            ans1.pb(i);
            amt-=i;
        }
        else
            ans2.pb(i);
    }
    if(amt != 0){
        cout << "NO" << '\n';
        return;
    }
    cout << "YES" << '\n';
    cout << ans1.size() << '\n';
    for(int i = ans1.size()-1; i >= 0; i--)
        cout << ans1[i] << " ";
    cout << '\n';
    cout << ans2.size() << '\n';
    for(int i = ans2.size()-1; i >= 0; i--)
        cout << ans2[i] << " ";
}  
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}