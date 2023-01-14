/*
Description: Binary indexed tree in one dimension
Time complexity: Query and single point update in O(logn)
*/

#include <bits/stdc++.h>
using namespace std;

class BIT1D{
public:
    int n;
    vector<ll> BIT;

    BIT1D(int _n){
        n = _n;
        BIT.assign(n + 1, 0);
    }

    void reset(){
        BIT.assign(n + 1, 0);
    }

    ll Query(int p){
        ll res = 0;
        for(; p > 0; p -= (p & (-p)))
            res = max(res, BIT[p]);

        return res;
    }

    void Update(int p, ll x){  
        for(; p <= n; p += (p & (-p)))
            BIT[p] = max(BIT[p], x);
    }
};
