struct LCA {
    int n;
    int maxN;
    vector<int> level;
    vector<vector<int>> lca;

    LCA(vector<vector<int>>& adj, int _n) {
        n = _n;
        maxN = 10;

        level.resize(n+1, -1);
        lca.resize(n+1);
        for(int i=0; i<=n; i++) {
            lca[i].resize(maxN+1);
            for(int j=0; j<=maxN; j++) {
                lca[i][j] = -1;
            }
        }

        dfsLCA(adj, 1, -1, 0);

        for(int i=1; i<=maxN; i++) {
            for(int j=1; j<=n; j++) {
                int par = lca[j][i-1];
                if(par != -1) {
                    lca[j][i] = lca[par][i-1];
                }
            }
        }
    }

    void dfsLCA(vector<vector<int>>& adj, int node, int par, int lvl) {
        level[node] = lvl;
        lca[node][0] = par;

        for(auto &i : adj[node]) {
            if(i != par)
                dfsLCA(adj, i, node, lvl+1);
        }
    }

    int getLCA(int a, int b) {
        if(level[a] > level[b]) {
            swap(a, b);
        }

        int dist = level[b] - level[a];
        while(dist > 0) {
            int diff = log2(dist);
            b = lca[b][diff];

            dist -= (1 << diff);
        }

        if(a == b) {
            return a;
        }

        for(int i=maxN; i>=0; i--) {
            if((lca[a][i] != -1) && (lca[a][i] != lca[b][i])) {
                a = lca[a][i];
                b = lca[b][i];
            }
        }

        return lca[a][0];
    }

    int getDist(int a, int b) {
        int currentLCA = getLCA(a, b);
        int dist = level[a] + level[b] - 2 * level[currentLCA];
        return dist;
    }
};
