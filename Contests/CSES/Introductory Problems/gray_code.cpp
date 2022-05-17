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
    vs ans;
    ans.pb("0");
    ans.pb("1");
    for(int i = 2; i <= n; i++){
        ll before = ans.size();
        for(int j = before-1; j >= 0; j--)
            ans.pb(ans[j]);
        for(int j = 0; j < ans.size()/2; j++)
            ans[j]+='0';
        for(int j = ans.size()/2; j < ans.size(); j++)
            ans[j]+='1';
    }
    for(int i = 0; i < ans.size(); i++){
        str temp = ans[i];
        reverse(temp.begin(), temp.end());
        cout << temp << '\n';
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