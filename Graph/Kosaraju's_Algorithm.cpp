// This algorithm is used to find the strongly connected components

vector<int> outOrder, ans;
void dfs1(vector<vector<int>>& adj, int curr, vector<bool>& vis) {
    vis[curr] = true;
    
    for(auto &i : adj[curr]) {
        if(!vis[i]) {
            dfs1(adj, i, vis);
        }
    }
    
    outOrder.push_back(curr);
}

void dfs2(vector<vector<int>>& transpose, int curr, vector<bool>& vis) {
    vis[curr] = true;
    
    for(auto &i : transpose[curr]) {
        if(!vis[i]) {
            dfs2(transpose, i, vis);
        }
    }
    
    ans.push_back(curr);
}

void solve() {
    int n, m;
    cin>>n>>m;
    
    outOrder.clear();
    
    vector<vector<int>> adj(n+1), transpose(n+1);
    for(int i=0, u, v; i<m; i++) {
        cin>>u>>v;
        
        adj[u].push_back(v);
        transpose[v].push_back(u);
    }
    
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs1(adj, i, vis);
        }
    }
    
    vis.assign(n+1, false);
    reverse(outOrder.begin(), outOrder.end());
    
    for(auto &i : outOrder) {
        if(!vis[i]) {
            ans.clear();
            dfs2(transpose, i, vis);
            print(ans);
        }
    }
}
