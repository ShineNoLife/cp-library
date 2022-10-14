struct SegTree_P{
    SegTree_P *left = NULL, *right = NULL;
    int val;
    const bool LAZY_UPDATE = false;
#define mid ((tl+tr) >> 1)
    SegTree_P(int tl, int tr) : val(0) {
        if(tl == tr)
            return;
        left = new SegTree_P(tl, mid);
        right = new SegTree_P(mid+1, tr);
    }

    SegTree_P() : val(0) {
        
    }

    SegTree_P* Update(int tl, int tr, int l, int r, ll x){
        if(r < tl || tr < l)
            return this;
        if(l <= tl && tr <= r){
            SegTree_P *cur = new SegTree_P(*this);
            cur->val = x;
            return cur;
        }

        SegTree_P *cur = new SegTree_P(*this);
        if(LAZY_UPDATE)
            cur->Push();
        cur->left = cur->left->Update(tl, mid, l, r, x);
        cur->right = cur->right->Update(mid+1, tr, l, r, x);
        cur->Pull();

        return cur;
    }

    int Query(int tl, int tr, int l, int r){
        if(r < tl || tr < l)
            return 0;
        if(l <= tl && tr <= r)
            return val;
        if(LAZY_UPDATE)
            Push();
        return left->Query(tl, mid, l, r) + right->Query(mid+1, tr, l, r);
    }
 
    void Push(){
        // if(lazy%2 != 0){
        //     left = new SegTree_P(*left);
        //     right = new SegTree_P(*right);
        //     left->val += lazy;
        //     right->val += lazy;
        //     left->lazy += lazy;
        //     right->lazy += lazy;
        //     lazy = 0;
        // }
    }

    void Pull(){
        val = left->val + right->val;
    }
#undef mid
};
