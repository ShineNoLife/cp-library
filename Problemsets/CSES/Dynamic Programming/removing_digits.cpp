#include <bits/stdc++.h>
 
#define ll long long
#define str string
#define db double
 
#define pii pair<int, int>
#define pll pair<ll, ll>
#define pdb pair<db, db>
 
#define vi vector<int>
#define vl vector<ll>
#define vdb vector<db>
#define vb vector<bool>
#define vs vector<str>
#define vpii vector<pi>
#define vpll vector<pl>
#define vpd vector<pd>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL)
 
//pairs
#define mp make_pair
#define fi first
#define se second
 
//vectors
#define pb push_back
#define pf push_front
 
//loops
#define FOR(i, a, b) for(int i=(int)a;i<(int)b;++i)
#define ROF(i, a, b) for(int i=(int)a-1;i>=(int)b;i--)
#define rep(a, x) for(auto& a : x)
 
const int MOD = 1e9+7;
const ll INF = 1e18;
 
using namespace std;
 
void solve(){
    ll n;
    cin >> n;
    ll dp[n+1] = {};
    dp[0] = 0;
    FOR(i, 1, n+1){
        dp[i] = INF;
        ll cur = i;
        while(cur > 0){
            dp[i] = min(dp[i], dp[i-(cur%10)]+1);
            cur/=10;
        }
    }
    cout << dp[n] << endl;
}
 
int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #else
    //freopen("allstars.inp", "r", stdin);
    //freopen("allstars.out", "w", stdout);
    #endif
    solve();
}