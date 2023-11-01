struct segtree_p_t {
    segtree_p_t *left = NULL, *right = NULL;
    int val;

    segtree_p_t(int tl = 0, int tr = 0) : val(0) {
        if(tl == tr)
            return;

        int mid = (tl + tr) >> 1;

        left = new segtree_p_t(tl, mid);
        right = new segtree_p_t(mid+1, tr);
    }
 
    segtree_p_t* Update(int tl, int tr, int l, int r, int x) {
        if (l > r)
            return this;

        if (l == tl && tr == r) {
            segtree_p_t *cur = new segtree_p_t(*this);
            cur->val += x;

            return cur;
        }
        
        segtree_p_t *cur = new segtree_p_t(*this);

        int mid = (tl + tr) >> 1;

        if (r <= mid) {
            cur->left = cur->left->Update(tl, mid, l, r, x);
            cur->right = right;
        }
        else if (l > mid) {
            cur->left = left;
            cur->right = cur->right->Update(mid + 1, tr, l, r, x);
        }

        cur->Pull();
        
        return cur;
    }
    
    int Query(int tl, int tr, int l, int r) {
        if (l > r) return 0;

        if (l == tl && tr == r)
            return val;

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
