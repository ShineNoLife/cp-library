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
 
str s;
vector<char> temp;
map<str, ll> cnt;
bool chosen[10];
 
void recur(){
    for(int i = 0; i < s.size(); i++){
        if(!chosen[i]){
            chosen[i] = true;
            temp.pb(s[i]);
            if(temp.size() == s.size()){
                str curs = "";
                for(int j = 0; j < s.size(); j++)
                    curs+=temp[j];
                cnt[curs]++;
            }
            else
                recur();
            chosen[i] = false;
            temp.pop_back();
        }
    }
}
 
void solve(){
    cin >> s;
    memset(chosen, false, sizeof(chosen));
    recur();
    cout << cnt.size() << '\n';
    for(pair<str, ll> p : cnt){
        cout << p.fi << '\n';
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