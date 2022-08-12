#include <bits/stdc++.h>

const int MAXN = 2e5+77;
int n, id = 1, scc = 0;
bool onstack[MAXN];
int num[MAXN], low[MAXN];
vector<int> adj[MAXN];
stack<int> stk;

void dfs(int u){
    onstack[u] = true;
    num[u] = low[u] = id++;
    stk.push(u);
    for(int i = 0; i < adj[u].size(); i++){
        if(!num[adj[u][i]])
            dfs(adj[u][i]);
        if(onstack[adj[u][i]])
            low[u] = min(low[u], low[adj[u][i]]);
    }
    if(low[u] == num[u]){
        while(stk.size()){
            int cur = stk.top();
            stk.pop();
            onstack[cur] = false;
            low[cur] = low[u];
            if(cur == u)
                break;
        }
        scc++;
    }
}  

int main(){
    
}
