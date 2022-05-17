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
 
ll calc(ll val){
    ll cur = 1, ans = 0;
    for(int i = 1; i <= 17; i++){
        if(cur > val)
            break;
        ans+=(min(val, cur*10-1)-cur+1)*i;
        cur*=10;
    }
    return ans;
}
 
void solve(){
    ll n;
    cin >> n;
    ll l = 0, r = 1e17;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(calc(mid) < n)
            l = mid;
        else
            r = mid-1;
    }
    ll val = l+1;
    str temp = "";
    while(val){
        temp+=(char)('0'+val%10);
        val/=10;
    }
    reverse(temp.begin(), temp.end());
    cout << temp[n-calc(l)-1] << '\n';
}  
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin >> t;
    while(t--)
        solve();
}