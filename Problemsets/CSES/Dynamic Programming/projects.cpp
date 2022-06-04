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

class SegTree{
    typedef ll T;
    int n;
    vector<T> a, tree, lazy;
    vector<bool> marked;
    T merge(T a, T b){
        return max(a, b);
    }
    void build(int v, int tl, int tr){
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2; 
            build(v*2, tl, tm);
            build(v*2+1, tm+1, tr);
            tree[v] = merge(tree[v*2], tree[v*2+1]);
        }
    }
    void push(int v, int tl, int tr){
        //update child first, push later
        /*addition update*/
        // tree[v*2] += lazy[v];
        // lazy[v*2] += lazy[v];
        // tree[v*2+1] += lazy[v];
        // lazy[v*2+1] += lazy[v];
        // lazy[v] = 0;
        /*set value update*/
        if(marked[v]){
            tree[2*v] = tree[2*v+1] = tree[v];
            marked[2*v] = marked[2*v+1] = true;
            marked[v] = false;
        }
    }
    T query(int v, int tl, int tr, int l, int r){
        if(l > r)
            return -1000000000;
        if(tl == l && tr == r)
            return tree[v];
        push(v, tl, tr);
        int tm = (tl+tr)/2;
        T lq = query(v*2, tl, tm, l, min(tm, r)), rq = query(v*2+1, tm+1, tr, max(tm+1, l), r);
        return merge(lq, rq);
    }
    void update(int v, int tl, int tr, int l, int r, long long val){
        if(l > r)
            return;
        if(tl == l && tr == r){
            //is matched with range l - r, update first, push later
            /*addition update*/
            // tree[v]+=val;
            // lazy[v]+=val;
            /*set value update*/
            if(val > tree[v]){
                tree[v] = val;
                marked[v] = true;
            }
            return;
        }
        push(v, tl, tr);
        int tm = (tl+tr)/2;
        update(v*2, tl, tm, l, min(tm, r), val);
        update(v*2+1, tm+1, tr, max(tm+1, l), r, val);
        tree[v] = merge(tree[v*2], tree[v*2+1]);
    }

    public:
        void setup(const vector<T> &_a){
            a=_a;
            n=(int)(a.size());
            tree.assign(4*n, 0);
            lazy.assign(4*n, 0);
            marked.assign(4*n, false);
            build(1, 0, n-1);
        }
        T query(int l, int r){
            return query(1, 0, n-1, l, r);
        }
        void update(int l, int r, long long val){
            update(1, 0, n-1, l, r, val);
        }
};

const int MAXN = 5e5+77;
vl temp(MAXN, 0);
SegTree seg;

void solve(){
    seg.setup(temp);
    ll n;
    cin >> n;
    map<ll, ll> cv;
    vector<pair<pll, ll>> v(n);
    vl ord;
    for(int i = 0; i < n; i++){
        cin >> v[i].fi.fi >> v[i].fi.se >> v[i].se;
        ord.pb(v[i].fi.fi);
        ord.pb(v[i].fi.se);
    }
    sort(all(ord));
    sort(all(v));
    ll cur = 1;
    cv[ord[0]] = 1;
    for(int i = 1; i < ord.size(); i++){
        if(ord[i] != ord[i-1])
            cur++;
        cv[ord[i]] = cur;
    }
    for(int i = 0; i < n; i++){
        v[i].fi.fi = cv[v[i].fi.fi];
        v[i].fi.se = cv[v[i].fi.se];
    }
    for(int i = 0; i < n; i++){
        ll amt = seg.query(0, v[i].fi.fi-1)+v[i].se;
        seg.update(v[i].fi.se, v[i].fi.se, amt);
    }
    cout << seg.query(0, MAXN-1) << '\n';
}

int main(){
    IOS;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    solve();
}