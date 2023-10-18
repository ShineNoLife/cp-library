struct Hungarian {
    int n, m;
    vector<vector<ll>> cost;

    Hungarian(int _n = 0, int _m = 0) {
        n = _n; m = _m;

        cost.assign(n + 1, {});
        for (int i = 0; i <= n; i++) 
            cost[i].assign(m + 1, 0);
    }

    void AddEdge(int u, int v, ll w) {
        cost[u][v] = w;
    }

    pair<ll, vector<pll>> match() {
        vector<ll> u(n + 1), v(m + 1), p(m + 1);

        for (int i = 1; i <= n; i++) {
            p[0] = i;

            vector<ll> dist(m + 1, INF), trace(m + 1, -1);
            vector<bool> vis(m + 1, false);

            // add "dummy" worker 0
            int j0 = 0;

            // dijkstra
            do {
                vis[j0] = true;

                int i0 = p[j0], j1;
                ll delta = INF;

                for (int j = 1; j <= m; j++) {
                    if (!vis[j]) {
                        ll cur = cost[i0][j] - u[i0] - v[j];

                        if (minimize(dist[j], cur))
                            trace[j] = j0;

                        if (minimize(delta, dist[j]))
                            j1 = j;
                    }
                }

                for (int j = 0; j <= m; j++) {
                    if (vis[j])
                        u[p[j]] += delta, v[j] -= delta;
                    else dist[j] -= delta;
                }

                j0 = j1;

            } while (p[j0]);

            // update alternating path
            while (j0) {
                int j1 = trace[j0];
                p[j0] = p[j1];
                j0 = j1;
            }
        }

        vector<pll> res;
        for (int i = 1; i <= m; i++)
            if (p[i])
                res.pb({p[i], i});

        ll C = -v[0];

        return {C, res};
    }
};