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
        return min(a, b);
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
        tree[v*2] += lazy[v];
        lazy[v*2] += lazy[v];
        tree[v*2+1] += lazy[v];
        lazy[v*2+1] += lazy[v];
        lazy[v] = 0;
        /*set value update*/
        // if(marked[v]){
        //     tree[2*v] = tree[2*v+1] = tree[v];
        //     marked[2*v] = marked[2*v+1] = true;
        //     marked[v] = false;
        // }
    }
    T query(int v, int tl, int tr, int l, int r){
        if(l > r)
            return INF;
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
            tree[v]+=val;
            lazy[v]+=val;
            /*set value update*/
            //tree[v] = val;
            //marked[v] = true;
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


void solve(){
    ll n, a, b;
    cin >> n >> a >> b;
    vl v(n+1), pref(n+1);
    for(int i = 1; i <= n; i++)
        cin >> v[i];
    pref[0] = 0;
    for(int i = 1; i <= n; i++)
        pref[i] = pref[i-1]+v[i];
    SegTree seg;
    seg.setup(pref);
    ll ans = -INF;
    for(int i = 1; i <= n; i++){
        ll l = max(0ll, i-b), r = max(0ll, i-a);
        if(i-a < 0)
            continue;
        ans = max(ans, pref[i]-seg.query(l, r));
    }
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