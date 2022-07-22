/*
Description: Disjoin set union implementation
Optimizations: path compression and balanced trees with log(n) height
*/
#include <bits/stdc++.h>
using namespace std;

const int MAXN = 2e5+77;
int par[MAXN], rnk[MAXN];

void setup(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
        rnk[i] = 1;
    }
}

int getPar(int u){
    if(par[u] == u)
        return par[u];
    par[u] = getPar(par[u]);
    return par[u];
}

void unite(int x, int y){
    int p1 = getPar(x), p2 = getPar(y);
    if(p1 == p2)
        return;
    if(rnk[p1] > rnk[p2])
        par[p2] = p1;
    else
        par[p1] = p2, rnk[p2] = max(rnk[p2], rnk[p1]+1);
}

int main(){

}
