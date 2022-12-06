ll ccw(const Point &P0, const Point &P1, const Point &P2){
    return (P1 - P0) ^ (P2 - P1);
}

ll sgn(const ll &x) { return (x >= 0 ? (x ? 1 : 0) : -1); }

bool insideConvex(Point p, vector<Point> &poly){
    int n = sz(poly);
    ll cl, cr;
    
    ll l = 1, r = n-1;
    while(l < r){
        ll mid = (l+r+1)/2;
        if(ccw(poly[0], p, poly[mid]) >= 0) l = mid;
        else r = mid - 1;
    }
    cl = l;

    l = 1, r = n-1;
    while(l < r){
        ll mid = (l+r)/2;
        if(ccw(poly[0], p, poly[mid]) <= 0) r = mid;
        else l = mid + 1;
    }
    cr = r;

    if(cl == cr) return ((cl == 1 || cl == n-1) ? false : true);
    ll e1, e2, e3;
    e1 = sgn(ccw(poly[0], poly[cl], p));
    e2 = sgn(ccw(poly[cl], poly[cr], p));
    e3 = sgn(ccw(poly[cr], poly[0], p));

    return (e1 == e2 && e2 == e3);
}