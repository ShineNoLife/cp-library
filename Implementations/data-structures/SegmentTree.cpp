class SegTree{
public:
    SegTree *left = NULL, *right = NULL;
    ll lazy, val;
#define mid ((tl+tr) >> 1)
    SegTree(int tl, int tr) : lazy(0), val(0) {
        if(tl == tr){
            val = 0;
            return;
        }

        left = new SegTree(tl, mid, v);
        right = new SegTree(mid+1, tr, v);
        Pull();
    }

    void Update(int tl, int tr, int l, int r, ll x){
        if(r < tl || tr < l)
            return;

        if(l <= tl && tr <= r){
            val += x;
            lazy += x;
            return;
        }

        Push();
        left->Update(tl, mid, l, r, x);
        right->Update(mid+1, tr, l, r, x);
        Pull();
    }

    ll Query(int tl, int tr, int l, int r){
        if(r < tl || tr < l)
            return INF;

        if(l <= tl && tr <= r)
            return val;

        Push();
        return min(left->Query(tl, mid, l, r), right->Query(mid+1, tr, l, r));
    }

    void Push(){
        left->val += lazy;
        right->val += lazy;
        left->lazy += lazy;
        right->lazy += lazy;
        lazy = 0;
    }

    void Pull(){
        val = min(left->val, right->val);
    }
#undef mid
};
