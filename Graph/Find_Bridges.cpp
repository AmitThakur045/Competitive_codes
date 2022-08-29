vector<int> low, in;
set<pair<int, int>> st;
int timer;

void bridge(vector<vector<int>>& adj, int curr, int par, vector<bool>& vis) {
    vis[curr] = true;
    low[curr] = in[curr] = timer++;
    
    for(auto &i : adj[curr]) {
        if(i == par) continue;
        if(vis[i]) {
            low[curr] = min(low[curr], in[i]);
        } else {
            bridge(adj, i, curr, vis);
            low[curr] = min(low[curr], low[i]);
            
            if(low[i] > in[curr]) {
                st.insert({curr, i});
            }
        }
    }
}

void find_Bridge(vector<vector<int>>& adj, int n) {
    timer = 0;
    low.assign(n+1, -1);
    in.assign(n+1, -1);
    
    vector<bool> vis(n+1, false);
    
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            bridge(adj, i, -1, vis);
        }
    }
}

void solve() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1);
    for(int i=0, u, v; i<m; i++) {
        cin>>u>>v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    find_Bridge(adj, n);
    
    for(auto &i : st) {
        cout<<i.first<<" "<<i.second<<endl;
    }
}
