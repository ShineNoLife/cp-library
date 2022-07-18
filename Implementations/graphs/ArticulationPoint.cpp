#include <bits/stdc++.h>

const int MAXN = 2e5+77;
int n, m, id = 0;
int low[MAXN], num[MAXN], cntChild[MAXN];
pair<int, int> edge[MAXN];
vector<int> adj[MAXN];
bool used[MAXN], isPoint[MAXN];

void dfs(int u){
    low[u] = 1e9;
    id++;
    num[u] = id;
    for(int pos : adj[u]){
        if(!used[pos]){
            used[pos] = true;
            int v = edge[pos].fi+edge[pos].se-u;
            if(num[v] == 0){
                cntChild[u]++;
                cntPar[v]++;
                dfs(v);
                low[u] = min(low[u], low[v]);
                if(low[v] >= num[u])
                    isPoint[u] = true;
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
    memset(cntChild, 0, sizeof(low[0])*n);
    memset(cntPar, 0, sizeof(cntPar[0])*n);
    memset(isPoint, false, sizeof(isPoint[0])*n);
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
        if(!num[i])
            dfs(i);
        if(cntChild[i] == 0 || (cntPar[i] == 0 && cntChild[i] <= 1))
            isPoint[i] = false;
    }
}
