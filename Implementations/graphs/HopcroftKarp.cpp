/*
hopcroft karp for finding maximum matching on bipartite graphs
time complexity : O(E.sqrt(V))
layL[i] is the bfs layer of the ith vertex of left partition 
layR[i] is for the ith vertex of the right partition
mtR[i] is the vertex matched with the ith vertex of right partition, -1 if unmatched
adj[i] is list of neighbours of ith vertex of left partition
*/

struct hopcroft {
    ll nl, nr;

    // adj list of the left partition
    vector<vector<int>> adj;
    vector<int> layL, layR, mtR, cur, nxt;

    vector<bool> vis[2], mark;

    hopcroft(int n, int m) : nl(n), nr(m) { 
        adj.assign(n, {});
    }

    bool dfs(int u, int len) {
        if(layL[u] != len) return 0;

        layL[u] = -1;
        for (int v : adj[u]) {
            if (layR[v] == len + 1) {
                layR[v] = 0;
                if (mtR[v] == -1 || dfs(mtR[v], len + 1))
                    return mtR[v] = u, 1;
            }
        }

        return 0;
    }

    ll max_matching() {
        layL.assign(nl, 0);
        layR.assign(nr, 0);
        mtR.assign(nr, -1);

        ll res = 0;
        
        while (true) {
            fill(all(layL), 0);
            fill(all(layR), 0);
            cur.clear();

            for (int u : mtR)
                if(u != -1) layL[u] = -1;

            for (int i = 0; i < sz(adj); i++)
                if (layL[i] != -1)
                    cur.pb(i);

            bool isLast = false;
            for (int lay = 1; ; lay++) {
                nxt.clear();

                for (int u : cur) {
                    for (int v : adj[u]) {
                        if (mtR[v] == -1) {
                            layR[v] = lay;
                            isLast = true;
                        }
                        else if (mtR[v] != u && !layR[v]) {
                            layR[v] = lay;
                            nxt.pb(mtR[v]);
                        }
                    }
                }

                if (isLast) break;

                if (nxt.empty()) return res;

                for (int u : nxt)
                    layL[u] = lay;

                swap(cur, nxt);
            }

            for (int i = 0; i < sz(adj); i++)
                res += dfs(i, 0);
        }    
    }

    void dfs2(int u, int l) {
        vis[l][u] = true;

        if (!l) {
            for (int v : adj[u]) {
                if (!vis[1][v])
                    dfs2(v, 1);
            }
        }
        else {
            if (mtR[u] != -1 && !vis[0][mtR[u]]) 
                dfs2(mtR[u], 0);
        }
    }

    //edges in matching -> right to left, else left to right 
    //return {left/right, index} of minimum cover
    vector<pll> minCover() {
        vis[0].assign(nl, false);
        vis[1].assign(nr, false);
        mark.assign(nl, false);
        
        vector<pll> res;
        for (int i = 0; i < nr; i++)
            if (mtR[i] != -1)
                mark[mtR[i]] = true;

        for (int i = 0; i < nl; i++)
            if (!mark[i])
                dfs2(i, 0);

        //unvisited of the left and visited of the right is in min cover
        for (int i = 0; i < nl; i++)
            if (!vis[0][i])
                res.pb({0, i});

        for (int i = 0; i < nr; i++)
            if (vis[1][i])
                res.pb({1, i});

        return res;
    }
};
