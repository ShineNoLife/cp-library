const int MOD = 1e9+7;
const int maxn = 1e6 + 16;
ll fact[maxn + 1];

ll binpow(ll a, ll b) {
    ll res = 1;

    while(b) {
        if (b & 1)
            res = (res * a) % MOD;

        a = (a * a) % MOD;
        b >>= 1;
    }

    return res;
}

void FactSetup() {
    fact[0] = 1;
    for (int i = 1; i <= maxn; i++)
        fact[i] = (fact[i-1] * i) % MOD;
}

ll C(int n, int k) {
    if(k > n) 
        return 0;
    return ((fact[n] * binpow(fact[k], MOD - 2)) % MOD * binpow(fact[n - k], MOD - 2)) % MOD;
}

