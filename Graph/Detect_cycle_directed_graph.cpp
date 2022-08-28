bool dfs(vector<vector<int>>& adj, int curr, vector<int>& color) {
    color[curr] = 1;
    for(auto &i : adj[curr]) {
        if (color[i] == 0) {
            if (dfs2(adj, i, color))
                return true;
        } else if (color[i] == 1) {
            return true;
        }
    }
    color[curr] = 2;
    return false;
}

bool find_cycle(vector<vector<int>>& adj, int n) {
    vector<int> color(k, 0);
    for(int i=0; i<n; i++) {
        if(color[i] == 0 && dfs(adj, i, vis)) {
            return true;
        }
    }
    return false;
}
