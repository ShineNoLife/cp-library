struct Line {
    ll m, b;

    Line(ll _m = 0, ll _b = INF * 8) : m(_m), b(_b) { }
};

ll F(Line l, ll x) {
    return l.m * x + l.b;
}

struct lichao_t {
    lichao_t *left = nullptr, *right = nullptr;
    Line mn;

    lichao_t(ll tl = 0, ll tr = 0) { }

    void Update(ll tl, ll tr, Line nLine) {
        ll mid = (tl + tr) >> 1;

        bool pLeft = (F(nLine, tl) < F(mn, tl));
        bool pMid = (F(nLine, mid) < F(mn, mid));

        if (pMid) swap(mn, nLine);

        if (tl == tr) return;

        if (pLeft != pMid) {
            if (left == nullptr) left = new lichao_t();

            left->Update(tl, mid, nLine);
        }
        else {
            if (right == nullptr) right = new lichao_t();

            right->Update(mid + 1, tr, nLine);
        }
    }
    
    ll Query(ll tl, ll tr, ll x) {
        if (tl == tr) return F(mn, x);

        ll mid = (tl + tr) >> 1;

        ll res = F(mn, x);

        if (x <= mid) {
            if (left != nullptr)
                minimize(res, left->Query(tl, mid, x));
        }
        else {
            if (right != nullptr)
                minimize(res, right->Query(mid + 1, tr, x));
        }
        
        return res;
    }
};