const int maxn = 2e5 + 25;
vector<ll> adj[maxn];
ll sub[maxn], par[maxn];
bool del[maxn];

int dfsSz(int u, int p) {
    sub[u] = 1;

    for (int v : adj[u]) {
        if (del[v] || v == p) continue;

        sub[u] += dfsSz(v, u);
    }

    return sub[u];
}

int findCentroid(int u, int p, int dsz) {
    for (int v : adj[u]) {
        if (del[v] || v == p) continue;

        if (sub[v] > (dsz >> 1)) return findCentroid(v, u, dsz);
    }

    return u;
}

void centroidDecompose(int u, int p = -1) {
    int cen = findCentroid(u, p, dfsSz(u, p));

    par[cen] = (p == -1 ? cen : p);
    del[cen] = true;

    for (int v : adj[cen]) {
        if (del[v]) continue;

        centroidDecompose(v, cen);
    }
}
