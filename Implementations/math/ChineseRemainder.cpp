struct euclid_T { ll x, y, d; };

euclid_T ex_euclid(ll a, ll b){
    if (b == 0) return {1, 0, a};

    euclid_T res = ex_euclid(b, a % b);
    return {res.y, res.x - a / b * res.y, res.d};
}

pll crt(vector<ll> r, vector<ll> m){
    //find x such that for (1 <= i <= n): x = r[i] (mod m[i]) 
    //return {y, z} where x = y (mod z), z = lcm of vector m
    //all solutions are congruent modulo z

    ll y = r[0], z = m[0];
    for(int i = 1; i < sz(r); i++){
        euclid_T cur = ex_euclid(z, m[i]);

        ll x = cur.x, d = cur.d;

        if((r[i] - y) % d != 0) return {0, 0};

        //ca mod cb = c(a mod b)
        //y = y + (x * (r[i] - y) / d * z) % (m[i] / d * z)
        y = y + ((x * (r[i] - y) / d) % (m[i] / d)) * z;
        z = z / d * m[i];

        y %= z;
        if(y < 0) y += z;
    }

    return {y, z};
}