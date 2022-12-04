ll ccw(Point &p1, Point &p2, Point &p3){
    return (p2 - p1) ^ (p3 - p2);
}

ll wn_poly(Point p, vector<Point> &poly){
    const ll on_boundary = INF;
    ll wn = 0;

    int n = sz(poly);
    for(int i = 0; i < n; i++){
        if(p == poly[i]) return on_boundary;

        int j = (i + 1 != n ? i + 1 : 0);
        
        if(poly[i].y == p.y && poly[j].y == p.y){
            if(min(poly[i].x, poly[j].x) <= p.x
                 && p.x <= max(poly[i].x, poly[j].x))
                return on_boundary;
        }
        else{
            bool below = (poly[i].y <= p.y);
            //different sides of horizontal ray
            if (below != (poly[j].y <= p.y)){
                ll orientation = ccw(p, poly[i], poly[j]);

                if (orientation == 0) return on_boundary;
                if (below == (orientation > 0)) wn += (below ? 1 : -1);
            }
        }
    }

    return wn;
}
