/*
Description: Dijkstra SSSP implementation with priority_queue
*/
#include <bits/stdc++.h>
using namespace std;

using pll = pair<long long, long long>;

const int MAXN = 2e5+77;
vector<int> adj[MAXN], cost[MAXN];
long long dist[MAXN];
bool visited[MAXN];

void dijkstra(int n){
    for(int i = 1; i <= n; i++)
        dist[i] = INF, vis[i] = false;
    
    priority_queue<pll, vector<pll>, greater<pll>> pq;
    dist[1] = 0;
    pq.push({0, 1});

    while(pq.size()){
        int u = pq.top().S; pq.pop();

        if(vis[u]) continue;

        vis[u] = true;
        for(int i = 0; i < adj[u].size(); i++){
            int v = adj[u][i];
            if(!vis[v] && dist[v] > dist[u] + cost[u][i]){
                dist[v] = dist[u] + cost[u][i];
                pq.push({dist[v], v});
            }
        }

    }

    cout << dist[n] << '\n';
}

int main(){

}
