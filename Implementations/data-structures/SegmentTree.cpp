class SegTree{
    SegTree *left, *right;
    int tl, tr, mid, lazy, val;

    SegTree(int _tl, int _tr) : tl(_tl), tr(_tr), mid((_tl + _tr) >> 1), lazy(0), val(0) {
        if(tl == tr)
            return;
        left = new SegTree(tl, mid);
        right = new SegTree(mid+1, tr);
    }

    void Update(int l, int r, int x){
        if(r < tl || tr < l)
            return;
        if(l <= tl && tr <= r){
            val += x;
            lazy += x;
            return;
        }

        Push();
        left->Update(l, r, x);
        right->Update(l, r, x);
        val = left->val + right->val;
    }

    int Query(int l, int r){
        if(r < tl || tr < l)
            return 0;
        if(l <= tl && tr <= r)
            return val;
        return val = left->Query(tl, tr) + right->Query(tl, tr);
    }

    void Push(){
        left->val += lazy;
        right->val += lazy;
        left->lazy += lazy;
        right->lazy += lazy;
        lazy = 0;
    }
};