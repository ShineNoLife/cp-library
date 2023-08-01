/*
Description: Binary indexed tree in one dimension
Time complexity: Query and single point update in O(logn)
*/

#include <bits/stdc++.h>
using namespace std;

class BIT_t {
public:
    int n;
    vector<ll> bit;

    BIT1D(int _n){
        n = _n;
        bit.assign(n + 1, 0);
    }

    void reset() {
        bit.assign(n + 1, 0);
    }

    ll Query(int p) {
        ll res = 0;

        for(; p > 0; p -= (p & (-p)))
            res += bit[p];

        return res;
    }

    void Update(int p, ll x) {
        for(; p <= n; p += (p & (-p)))
            bit[p] += x;
    }
};
