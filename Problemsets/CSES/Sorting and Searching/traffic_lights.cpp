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

void solve(){
    ll n, k;
    cin >> k >> n;
    vl v(n), leftp(n), rightp(n);
    vpll temp;
    for(int i = 0; i < n; i++)
        cin >> v[i];
    for(int i = 0; i < n; i++)
        temp.pb(mp(v[i], i));
    sort(all(temp));
    stack<pll> q;
    q.push(mp(-1, -1));
    for(int i = 0; i < n; i++){
        while(q.size() && q.top().fi >= temp[i].se)
            q.pop();
        if(q.top().se == -1)
            leftp[temp[i].se] = 0;
        else
            leftp[temp[i].se] = temp[q.top().se].fi;
        q.push(mp(temp[i].se, i));
    }
    while(q.size())
        q.pop();
    q.push(mp(-1, -1));
    for(int i = n-1; i >= 0; i--){
        while(q.size() && q.top().fi >= temp[i].se)
            q.pop();
        if(q.top().se == -1)
            rightp[temp[i].se] = k;
        else
            rightp[temp[i].se] = temp[q.top().se].fi;
        q.push(mp(temp[i].se, i));
    }
    map<ll, ll> cnt;
    map<ll, ll>::iterator it;
    cnt[k]++;
    for(int i = 0; i < n; i++){
        ll cur = rightp[i]-leftp[i];
        cnt[cur]--;
        if(cnt[cur] == 0)
            cnt.erase(cur);
        cnt[v[i]-leftp[i]]++;
        cnt[rightp[i]-v[i]]++;
        it = cnt.end();
        cout << (*--it).fi << " ";
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