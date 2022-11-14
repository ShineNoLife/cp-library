struct MaxFlow{
    struct Edge{
        ll from, to;
        ll flow, cap;

        int oth(int u){
            return (u ^ from ^ to);
        }

        ll capacity(int u){
            return (u == from ? cap - flow : flow);
        }

        void updateFlow(int u, ll dF){
            if(u == from) flow += dF;
            else flow-= dF;
        }
    };

    ll source, sink, n;
    vector<vector<Edge*>> adj;
    vector<bool> blocked;
    vector<int> layer;

    void Setup(int _n){
        n = _n;
        adj.resize(_n+1, {});
        blocked = vector<bool> (n+1, false);
    }

    void addEdge(tuple<int, int, ll> ee){
        Edge *ce = new Edge();
        ce->from = get<0>(ee), ce->to = get<1>(ee);
        ce->cap = get<2>(ee), ce->flow = 0;
        if(ce->from != ce->to){
            adj[ce->from].pb(ce);
            adj[ce->to].pb(ce);
        }
    }

    bool inDAG(int u, int v){
        return (layer[v] == (layer[u] + 1));
    }

    void dBFS(){
        layer = vector<int> (n+1, n+10);
        layer[source] = 0;
        queue<int> q;
        q.push(source);

        while(q.size()){
            int u = q.front(); q.pop();

            for(Edge *e : adj[u]){
                if(e->capacity(u) == 0) continue;
                int v = e->oth(u);
                if(layer[v] > n){
                    layer[v] = layer[u] + 1;
                    q.push(v);
                }
            }
        }
    }

    ll dDFS(int u, ll F){
        if(u == sink) return F;
        ll pushed = 0;
        bool allBlocked = false;
        for(Edge *e : adj[u]){
            int v = e->oth(u);
            if(!inDAG(u, v)) continue;
            if(e->capacity(u) != 0 && !blocked[v]){
                ll dF = dDFS(v, min(F, e->capacity(u)));
                pushed+=dF;
                F-=dF;
                e->updateFlow(u, dF);
                if(F == 0) break;
            }
            if(e->capacity(u) != 0 && !blocked[v]) allBlocked = false;
        }
        if(allBlocked) blocked[u] = true;
        return pushed;
    }

    ll Calc(ll _source, ll _sink){
        source = _source, sink = _sink;
        while(true){
            dBFS();
            if(layer[sink] > n) break;
            blocked = vector<bool> (n+1, false);
            dDFS(source, INF);
        }
        ll ans = 0;
        for(Edge *e : adj[source]){
            if(e->from == source) ans += e->flow;
            else ans -= e->flow;
        }
        return ans;
    }
};
