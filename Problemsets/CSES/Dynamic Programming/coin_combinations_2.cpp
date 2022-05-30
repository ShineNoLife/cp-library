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
    ll n, k, ans = 0;
    cin >> n >> k;
    vl v(n);
    ll dp[k+1], cnt[k+1] = {0};
    cnt[0] = 1;
    FOR(i, 0, n)
        cin >> v[i];
    FOR(i, 0, n){
        FOR(j, 1, k+1){
            dp[j] = 0;
            if(j-v[i] < 0)
                continue;
            dp[j]+=cnt[j-v[i]];
            dp[j]%=MOD;
            cnt[j]+=dp[j];
            cnt[j]%=MOD;
        }
    }
    cout << cnt[k] << endl;
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