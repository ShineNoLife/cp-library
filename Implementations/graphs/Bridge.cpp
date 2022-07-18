#include <bits/stdc++.h>

const int MAXN = 2e5+77;
int n, m, id = 0;
int low[MAXN], num[MAXN];
pair<int, int> edge[MAXN];
vector<int> adj[MAXN];
bool used[MAXN], bridge[MAXN];

void dfs(int u){
    low[u] = 1e9;
    id++;
    num[u] = id;
    for(int pos : adj[u]){
        if(!used[pos]){
            used[pos] = true;
            int v = edge[pos].fi+edge[pos].se-u;
            if(num[v] == 0){
                dfs(v);
                low[u] = min(low[u], low[v]);
                if(low[v] > num[u])
                    bridge[pos] = true;
            }
            else
                low[u] = min(low[u], num[v]);
        }
    }
}

void Input(){
    cin >> n >> m;
    memset(num, 0, sizeof(num[0])*n);
    memset(low, 0, sizeof(low[0])*n);
    memset(bridge, false, sizeof(bridge[0])*m);
    memset(used, false, sizeof(used[0])*m);
    for(int i = 0; i < m; i++){
        ll u, v;
        cin >> u >> v;
        u--; v--;
        edge[i] = mp(u, v);
        adj[u].pb(i);
        adj[v].pb(i);
    }
}

int main(){
    Input();
    for(int i = 0; i < n; i++){
        if(num[i] == 0)
            dfs(i);
    }    
}
