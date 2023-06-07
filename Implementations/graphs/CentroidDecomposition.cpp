const int maxn = 2e5 + 25;
vector<ll> adj[maxn];
ll sub[maxn], par[maxn];
bool vis[maxn];

ll dfsSz(int u, int p) {
    sub[u] = 1;

    for (int v : adj[u]) {
        if (v == p || vis[v]) continue;

        sub[u] += dfsSz(v, u);
    }

    return sub[u];
}

ll findCentroid(int u, int p, int n) {
    for (int v : adj[u]) {
        if (v == p || vis[v]) continue;

        if (sub[v] > n / 2) return findCentroid(v, u, n);
    }

    return u;
}

void centroidDecompose(int u, int p = -1) {
    dfsSz(u, p);
    ll cen = findCentroid(u, p, sub[u]);

    par[cen] = (p == -1 ? cen : p);
    vis[cen] = true;

    for (int v : adj[cen]) {
        if (vis[v]) continue;

        centroidDecompose(v, cen);
    }
}