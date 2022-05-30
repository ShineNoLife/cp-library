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
    vs v(n);
    ll dp[n][n];
    FOR(i, 0, n)
        cin >> v[i];
    if(v[0][0] == '*'){
        cout << 0 << endl;
        return;
    }
    dp[0][0] = 1;
    FOR(i, 1, n){
        dp[0][i] = 0;
        dp[i][0] = 0;
        if(v[0][i] == '.')
            dp[0][i]+=dp[0][i-1];
        dp[0][i]%=MOD;
        if(v[i][0] == '.')
            dp[i][0]+=dp[i-1][0];
        dp[i][0]%=MOD;
    }
    FOR(i, 1, n){
        FOR(j, 1, n){
            dp[i][j] = 0;
            if(v[i][j] == '*')
                continue;
            dp[i][j] = 0;
            if(j-1 >= 0)
                dp[i][j]+=dp[i][j-1];
            if(i-1 >= 0)
                dp[i][j]+=dp[i-1][j];
            dp[i][j]%=MOD;
        }
    }
    cout << dp[n-1][n-1] << endl;
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