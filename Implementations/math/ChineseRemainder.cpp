struct gcd_t { ll x, y, d; };
 
gcd_t e_gcd(ll a, ll b) {
    if (b == 0) return {1, 0, a};
 
    gcd_t res = e_gcd(b, a % b);

    return {res.y, res.x - res.y * (a / b), res.d};
}

pll crt(vector<ll> r, vector<ll> m) {
    //find x such that for (1 <= i <= n): x = r[i] (mod m[i]) 
    //return {y, z} where x = y (mod z), z = lcm of vector m
    //all solutions are congruent modulo z
 
    ll y = r[0], z = m[0];
    for (int i = 1; i < sz(r); i++) {
        gcd_t cur = e_gcd(z, m[i]);
            
        ll x = cur.x, d = cur.d;
            
        if((r[i] - y) % d != 0) return {-1, -1};
        
        //ka = kb (mod kc)   =>   a = b (mod c) if (gcd(k, c) = 1)
        //add (x * (r[i] - y) / d * z) to result (with moduli lcm(z, m[i]))
        ll tmp = (x * (r[i] - y) / d) % (m[i] / d);
        y = y + tmp * z;
        z = z / d * m[i];
        
        y %= z;
        if (y < 0) y += z;
    }
 
    return {y, z};
}

ll inverse(ll a, ll m) {
    gcd_t cur = e_gcd(a, m);
 
    return (cur.x % m + m) % m;
}
