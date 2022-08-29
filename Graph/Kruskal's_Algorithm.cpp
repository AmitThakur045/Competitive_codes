// This algo is use to find the minimum spanning tree.
// we can also use it to find maximum spanning tree just by adding some changes to comp function

struct UnionFind {
    vector<int> par;
    vector<int> size;
    UnionFind(int n) {
        par.resize(n);
        size.resize(n,1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return false;
        }
        if(size[x] > size[y]) {
            swap(x,y);
        }
        par[x] = y;
        size[y] += size[x];
        return true;
    }
};


struct edges {
    int u, v, wt;
    edges(int _u, int _v, int _wt) {
        u = _u;
        v = _v;
        wt = _wt;
    }
};

struct comp {
    bool operator()(edges& p1, edges& p2) {
        return p1.wt < p2.wt;
    }
};

void solve() {
    int n, m;
    cin>>n>>m;
    
    vector<edges> adj;
    
    for(int i=0, u, v, wt; i<m; i++) {
        cin>>u>>v>>wt;
        adj.push_back({u, v, wt});
    }
    
    // sort the edges nonDecreasing order of weight
    sort(adj.begin(), adj.end(), comp());
    
    UnionFind U(n+1);
    int weightSum = 0;
    for(int i=0; i<m; i++) {
        if(U.find(adj[i].u) != U.find(adj[i].v)) {
            U.unite(adj[i].u, adj[i].v);
            weightSum += adj[i].wt;
        }
    }
    
    cout<<weightSum<<endl;
}
