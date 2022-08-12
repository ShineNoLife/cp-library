#include <bits/stdc++.h>

const int MAXN = 2e5+77;
int n, id = 1, scc = 0;
int num[MAXN], low[MAXN];
vector<int> adj[MAXN];
stack<int> stk;

void dfs(int u){
    num[u] = low[u] = id++;
    stk.push(u);
    for(int v : adj[u]){
        if(num[v] == -1)
            continue;
        if(!num[v]){
            dfs(v);
            low[u] = min(low[u], low[v]);
        }
        else
            low[u] = min(low[u], num[v]);
    }
    if(low[u] == num[u]){
        while(stk.size()){
            int cur = stk.top();
            stk.pop();
            low[cur] = low[u];
            num[cur] = -1;
            if(cur == u)
                break;
        }
        scc++;
    }
}  

int main(){
    
}
