const int maxn = 2e5 + 25;
ll n, m, num[maxn], low[maxn], timed = 0, scc = 0;
vector<ll> adj[maxn], res[maxn];
pll edge[maxn];
bool used[maxn];
stack<ll> stk;

void dfs(int u) {
    num[u] = low[u] = ++timed;

    stk.push(u);
    for (int i : adj[u]) {
        if (used[i]) continue;

        used[i] = true;
        int v = edge[i].F + edge[i].S - u;

        if (!num[v]) {
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }

    if (low[u] == num[u]) {
        scc++;

        ll tmp;
        do {
            tmp = stk.top();
            num[tmp] = scc;
            res[scc].pb(tmp);
            stk.pop();

        }while (tmp != u);
    }
}

void solve() {
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll u, v;
        cin >> u >> v;

        edge[i] = {u, v};
        adj[u].pb(i);
        adj[v].pb(i);
    }
    for (int i = 0; i < m; i++)
        used[i] = false;

    for (int i = 0; i < n; i++)
        if(!num[i]) dfs(i);

    cout << scc << '\n';
    for (int i = 1; i <= scc; i++) {
        cout << res[i].size() << " ";
        for (int v : res[i]) cout << v << " ";
        cout << '\n';
    }
}
