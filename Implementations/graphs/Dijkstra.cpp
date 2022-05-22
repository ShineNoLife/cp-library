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
    for(int i = 0; i < n; i++){
        dist[i] = 1e18;
        visited[i] = false;
    }
    priority_queue<pll, vector<pll>, greater<pll>> q;
    dist[0] = 0;
    q.push({0, 0});
    while(q.size()){
        int u = q.top().second;
        q.pop();
        if(!visited[u]){
            visited[u] = true;
            for(int i = 0; i < adj[u].size(); i++){
                if(!visited[adj[u][i]] && dist[adj[u][i]] > dist[u]+cost[u][i]){
                    dist[adj[u][i]] = dist[u]+cost[u][i];
                    q.push({dist[adj[u][i]], adj[u][i]});
                }
            }
        }
    }
}

int main(){

}