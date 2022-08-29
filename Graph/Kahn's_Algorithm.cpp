vector<int> indeg, result;

void kahn_algorithm(vector<vector<int>>& adj, int n) {
    queue<int> q;
    for(int i=1; i<=n; i++) {
        if(indeg[i] == 0) {
            q.push(i);
        }
    }
    
    while(q.size()) {
        int node = q.front();
        result.push_back(node);
        q.pop();
        
        for(auto &i : adj[node]) {
            indeg[i]--;
            if(indeg[i] == 0) {
                q.push(i);
            }
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    
    indeg.resize(n+1, 0);
    
    vector<vector<int>> adj(n+1);
    for(int i=0, u, v; i<m; i++) {
        cin>>u>>v;
        
        adj[u].push_back(v);
        indeg[v]++;
    }
    
    kahn_algorithm(adj, n);
    
    print(result);
}
