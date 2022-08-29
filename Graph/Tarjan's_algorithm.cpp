// This algirithm is used to find the strongly connected component

vector<bool> isActive;
vector<int> in, low;
int timer;
stack<int> st;
vector<vector<int>> strong;

void dfs(vector<vector<int>>& adj, int curr, vector<bool>& vis) {
    vis[curr] = true;
    isActive[curr] = true;
    st.push(curr);
    in[curr] = low[curr] = timer++;
    
    for(auto &i : adj[curr]) {
        if(vis[i] == true && isActive[i] == true) {
            low[curr] = min(low[curr], in[i]);
        } else if(vis[i] == false) {
            dfs(adj, i, vis);
            
            if(isActive[i] == true) {
                low[curr] = min(low[curr], low[i]);
            }
        }
    }
    
    if(in[curr] == low[curr]) {
        vector<int> ans;
        while(true) {
            int num = st.top();
            st.pop();
            isActive[num] = false;
            ans.push_back(num);
            
            if(num == curr) {
                break;
            }
        }
        strong.push_back(ans);
    }
}


void solve() {
    int n, m;
    cin>>n>>m;
    
    vector<vector<int>> adj(n+1);
    for(int i=0, u, v; i<m; i++) {
        cin>>u>>v;
        
        adj[u].push_back(v);
    }
    
    while(st.size()) {
        st.pop();
    }
    strong.clear();
    isActive.clear();
    isActive.resize(n+1, false);
    in.resize(n+1, -1);
    low.resize(n+1, -1);
    timer = 0;
    
    vector<bool> vis(n+1, false);
    for(int i=1; i<=n; i++) {
        if(!vis[i]) {
            dfs(adj, i, vis);
        }
    }
    
    // printing the strong component;
    for(auto &i : strong) {
        print(i);
    }
    
}
