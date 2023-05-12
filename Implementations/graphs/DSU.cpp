struct DSU {
    int n;
    vector<int> par, rnk;
 
    DSU(int _n) {
        n = _n;
        par.assign(n + 1, 0);
        rnk.assign(n + 1, 0);
 
        for (int i = 0; i <= n; i++)
            par[i] = i, rnk[i] = 1;
    }
 
    int root(int u) {
        return (par[u] == u ? u : par[u] = root(par[u]));
    }
 
    bool unite(int x, int y) {
        int u = root(x), v = root(y);
 
        if (u == v) return false;
        if (rnk[u] < rnk[v]) swap(u, v);
 
        par[v] = u;
        rnk[u] += rnk[v];
 
        return true;
    }
};
