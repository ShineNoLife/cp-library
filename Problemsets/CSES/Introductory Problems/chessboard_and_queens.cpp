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
 
ll bd[10][10];
bool col[30], row[30], diag1[30], diag2[30];
 
ll recur(ll x, ll amt){
    if(amt == 0)
        return 1;
    ll ans = 0;
    for(int i = x; i < 8; i++){
        for(int j = 0; j < 8; j++){
            if(!col[i] && !row[j] && !diag1[i+j] && !diag2[i-j+10] && !bd[i][j]){
                col[i] = true;
                row[j] = true;
                diag1[i+j] = true;
                diag2[i-j+10] = true;
                ans+=recur(x+1, amt-1);
                col[i] = false;
                row[j] = false;
                diag1[i+j] = false;
                diag2[i-j+10] = false;
            }
        }
    }
    return ans;
}
 
void solve(){
    for(int i = 0; i < 8; i++){
        str s;
        cin >> s;
        for(int j = 0; j < 8; j++)
            bd[i][j] = (s[j] == '*');
    }
    memset(col, false, sizeof(col));
    memset(row, false, sizeof(row));
    memset(diag1, false, sizeof(diag1));
    memset(diag2, false, sizeof(diag2));
    ll ans = recur(0, 8);
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