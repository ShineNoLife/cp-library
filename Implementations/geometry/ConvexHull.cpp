ll ccw(const Point &P0, const Point &P1, const Point &P2){
    return (P1 - P0) ^ (P2 - P1);
}

vector<Point> convexHull(vector<Point> &v){
    Point piv = v[0];
    for(int i = 1; i < sz(v); i++){
        if(piv.y == v[i].y && piv.x < v[i].x) piv = v[i];
        if(piv.y > v[i].y) piv = v[i];
    }
    vector<Point> hull(sz(v));

    sort(all(v), [piv](const Point &P0, const Point &P1){
        Point V0 = P0 - piv, V1 = P1 - piv;
        ll orientation = V0 ^ V1;
        return (orientation > 0) || (orientation == 0 && V0.len2() < V1.len2());
    });

    int m = 0;
    for(int i = 0; i < sz(v); i++){
        while(m >= 2 && ccw(hull[m - 2], hull[m - 1], v[i]) <= 0)
            m--;

        hull[m++] = v[i];
    }

    return {hull.begin(), hull.begin() + m};
}