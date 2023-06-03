const int maxn = 1e5 + 15;
vector<ll> adj[maxn];
ll depth[maxn], subsize[maxn], par[maxn], nChain = 1, tour = 0;
ll chainTop[maxn], chain[maxn], hldInd[maxn];
SegTree seg(1, maxn);

void dfs(int u, int p) {
    depth[u] = depth[p] + 1; par[u] = p;
    subsize[u] = 1;

    for (int v : adj[u]) {
        if (v == p) continue;

        dfs(v, u);
        subsize[u] += subsize[v];
    }
}

void HLD(int u) {
    if (!chainTop[nChain]) chainTop[nChain] = u;

    chain[u] = nChain;
    hldInd[u] = ++tour;

    ll mxV = -1;
    for (int v : adj[u]) {
        if (v == par[u]) continue;

        if (mxV == -1 || subsize[v] > subsize[mxV])
            mxV = v;
    }

    if (mxV != -1) HLD(mxV);

    for (int v : adj[u]) {
        if (v == par[u]) continue;

        if (v != mxV)
            nChain++, HLD(v);
    }
}

//query path from u to v without LCA function
ll hldQuery(int u, int v) {
    ll res = 0;

    while (true) {
        if (chain[u] == chain[v]) {
            if (depth[u] > depth[v]) swap(u, v);

            res = max(res, seg.Query(1, maxn, hldInd[u], hldInd[v]));

            break;
        }

        if (depth[chainTop[chain[u]]] < depth[chainTop[chain[v]]]) swap(u, v);

        res = max(res, seg.Query(1, maxn, hldInd[chainTop[chain[u]]], hldInd[u]));

        u = par[chainTop[chain[u]]];
    }

    return res;
}