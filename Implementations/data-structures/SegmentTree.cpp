
//optimized classic top down implementation
void Update(int v, int tl, int tr, int l, int r, int x) {
    if (l == tl && tr == r) {
        seg[v] = x;
        return;
    }

    int mid = (tl + tr) >> 1;

    if(r <= mid)
        Update(v << 1, tl, mid, l, r, x);
    else if (l > mid)
        Update(v << 1 | 1, mid + 1, tr, l, r, x);

    seg[v] = max(seg[v << 1], seg[v << 1 | 1]);
}

int Query(int v, int tl, int tr, int l, int r) {
    if(l == tl && tr == r)
        return seg[v];

    int mid = (tl + tr) >> 1;

    if (r <= mid) 
        return Query(v << 1, tl, mid, l, r);
    else if(l > mid) 
        return Query(v << 1 | 1, mid + 1, tr, l, r);
    else 
        return max(Query(v << 1, tl, mid, l, mid), Query(v << 1 | 1, mid + 1, tr, mid + 1, r));
}



//---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


//pointer-based implementation
struct segtree_t {
    segtree_t *left, *right;
    ll val;

    segtree_t() { }
    
    segtree_t(int tl, int tr) : val(0) {    
        if (tl == tr) return;

        int mid = (tl + tr) >> 1;

        left = new segtree_t(tl, mid);
        right = new segtree_t(mid + 1, tr); 

        Pull();
    }

    void Update(int tl, int tr, int l, int r, ll x) {
        if (l > r) return;

        if (tl == l && tr == r) {
            val += x;

            return;
        }

        int mid = (tl + tr) >> 1;

        if (r <= mid) 
            left->Update(tl, mid, l, r, x);
        else if (l > mid)
            right->Update(mid + 1, tr, l, r, x);

        Pull();
    }

    ll Query(int tl, int tr, int l, int r) {
        if (l > r) return 0;

        if (tl == l && tr == r) return val;

        int mid = (tl + tr) >> 1;

        if (r <= mid)
            return left->Query(tl, mid, l, r);
        else if (l > mid)
            return right->Query(mid + 1, tr, l, r);
        else 
            return left->Query(tl, mid, l, mid) + right->Query(mid + 1, tr, mid + 1, r);
    }

    void Pull() {
        val = left->val + right->val;
    }
};
