/*
Description: Segment tree with lazy propagation with range addition and set value update and customizable query.
*/
#include <bits/stdc++.h>
using namespace std;

class SegTree{
    typedef int T;
    int n;
    vector<T> a, tree, lazy;
    T merge(T a, T b){
        return max(a, b);
    }
    void build(int v, int tl, int tr){
        if (tl == tr) {
            tree[v] = a[tl];
        } else {
            int tm = (tl + tr) / 2; 
            build((v << 1), tl, tm);
            build((v << 1)+1, tm+1, tr);
            tree[v] = merge(tree[(v << 1)], tree[(v << 1)+1]);
        }
    }
    void push(int v, int tl, int tr){
        //update child first, push later
        /*addition update*/
        tree[(v << 1)] += lazy[v];
        lazy[(v << 1)] += lazy[v];
        tree[(v << 1)+1] += lazy[v];
        lazy[(v << 1)+1] += lazy[v];
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
            return -1000000000;
        if(tl == l && tr == r)
            return tree[v];
        push(v, tl, tr);
        int tm = (tl+tr) >> 1;
        T lq = query((v << 1), tl, tm, l, min(tm, r)), rq = query((v << 1)+1, tm+1, tr, max(tm+1, l), r);
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
            // tree[v] = val;
            // marked[v] = true;
            return;
        }
        push(v, tl, tr);
        int tm = (tl+tr)/2;
        update((v << 1), tl, tm, l, min(tm, r), val);
        update((v << 1)+1, tm+1, tr, max(tm+1, l), r, val);
        tree[v] = merge(tree[(v << 1)], tree[(v << 1)+1]);
    }

    public:
        void setup(const vector<T> &_a){
            a=_a;
            n=(int)(a.size());
            tree.assign(4*n, 0);
            lazy.assign(4*n, 0);
            build(1, 0, n-1);
        }
        T query(int l, int r){
            return query(1, 0, n-1, l, r);
        }
        void update(int l, int r, long long val){
            update(1, 0, n-1, l, r, val);
        }
};

int main(){

}
