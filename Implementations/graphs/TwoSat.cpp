void dfs(int u) {
    vis[u] = true;

    for (int v : adj[u])
        if (!vis[v])
            dfs(v);

    ord.pb(u);
}

void dfs2(int u, int x) {
    val[u] = x;

    for (int v : adjT[u])
        if (val[v] == -1)
            dfs2(v, x);
}

void addRelation(int a, int na, int b, int nb) {
    a = (a << 1) ^ na;
    b = (b << 1) ^ nb;

    int negA = a ^ 1;
    int negB = b ^ 1;

    adj[negA].pb(b);
    adj[negB].pb(a);

    adjT[b].pb(negA);
    adjT[a].pb(negB);
}

bool twoSAT() {
    mem(val, -1);
    mem(vis, false);

    ord.clear();
    for (int i = 0; i < 2 * n; i++)
        if (!vis[i])
            dfs(i);

    reverse(all(ord));
    for (int i = 0, j = 0; i < 2 * n; i++)
        if (val[ord[i]] == -1)
            dfs2(ord[i], j++);

    for (int i = 0; i < 2 * n; i += 2) {
        if (val[i] == val[i + 1])
            return false;

        res[i / 2] = (val[i] > val[i + 1]);
    }

    return true;
}
