vector<int> low, in;
set<int> st;
int timer;

void articulation(vector<vector<int>>& adj, int curr, int par, vector<bool>& vis) {
    vis[curr] = true;
    low[curr] = in[curr] = timer++;
    int children = 0;
    
    for(auto &i : adj[curr]) {
        if(i == par) continue;
        if(vis[i] == true) {
            low[curr] = min(low[curr], in[i]); 
        } else {
            articulation(adj, i, curr, vis);
            low[curr] = min(low[curr], low[i]);
            
            // if the child of curr is not connected to any ancestor of curr 
            // then curr is an articulation point && curr should not be a root
            if(low[i] >= in[curr] && par != -1) {
                st.insert(curr);
            }
            children += 1;
        }
    }
    
    if(par == -1 && children > 1) {
        st.insert(curr);
    }
}

void find_Articulation_point(vector<vector<int>>& adj, int n) {
    vector<bool> vis(n+1, false);
    low.assign(n+1, -1);
    in.assign(n+1, -1);
    timer = 0;
    
    for(int i=1; i<=n; i++) {
        if(!vis[i])
            articulation(adj, i, -1, vis);
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
    
    st.clear();
    find_Articulation_point(adj, n);
    
    for(auto &i : st) {
        cout<<i<<" ";
    }
    cout<<endl;
}
