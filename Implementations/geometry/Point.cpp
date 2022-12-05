struct Point{
    typedef ll T;
    T x, y;
    Point(T _x = 0, T _y = 0) : x(_x), y(_y) {}

    bool operator < (Point p) const { return tie(x, y) < tie(p.x, p.y); }
    bool operator > (Point p) const { return tie(x, y) > tie(p.x, p.y); }
    bool operator == (Point p) const { return tie(x, y) == tie(p.x, p.y); }
    bool operator != (Point p) const { return tie(x, y) != tie(p.x, p.y); }

    Point operator + (Point p) const { return Point(x + p.x, y + p.y); }
    Point operator - (Point p) const { return Point(x - p.x, y - p.y); }
    T operator * (Point p) const { return x * p.x + y * p.y; }
    T operator ^ (Point p) const { return x * p.y - y * p.x; }

    Point operator * (T d) const { return Point(x * d, y * d); }
    Point operator / (T d) const { return Point(x / d, y / d); }

    T len2() const { return x * x + y * y; }
    T len() const { return sqrt(len2()); }
    friend ostream& operator << (ostream &os, const Point &p) {
        return os << "(" << p.x << ", " << p.y << ")"; }
};

ll sgn(const ll &x) { return (x >= 0 ? (x ? 1 : 0) : -1); }

ll ccw(const Point &P0, const Point &P1, const Point &P2){
    return (P1 - P0) ^ (P2 - P1);
}