struct PersistentSegTree{
    PersistentSegTree *left = NULL, *right = NULL;
    int val;

    PersistentSegTree(){

    }

    void Update(int tl, int tr, int l, int r, ll x){
        if(tl == tr){
            val = x;
            return;
        }
        int mid = (tl+tr)/2;
        if (tl <= l && l <= mid){
            left = left ? new PersistentSegTree(*left) : new PersistentSegTree();
            left->Update(tl, mid, l, r, x);
        } 
        if(mid+1 <= r && r <= tr){
            right = right ? new PersistentSegTree(*right) : new PersistentSegTree();
            right->Update(mid+1, tr, l, r, x);
        }
        val = 0;
        if(left)
            val+=left->val;
        if(right)
            val+=right->val;
    }

    int Query(int tl, int tr, int l, int r){
        if(r < tl || tr < l)
            return 0;
        if(l <= tl && tr <= r)
            return val;
        int res = 0;
        int mid = (tl+tr)/2;
        if(left)
            res+=left->Query(tl, mid, l, r);
        if(right)
            res+=right->Query(mid+1, tr, l, r);
        return res;
    }

    void Push(){
        // left->val += lazy;
        // right->val += lazy;
        // left->lazy += lazy;
        // right->lazy += lazy;
        // lazy = 0;
    }
};