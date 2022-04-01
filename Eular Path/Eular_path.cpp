#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ll unsigned long long 
#define lld long double

const int mod=1e9+7;
const int INF = (1LL << 60) - 1;

void component(int curr, vector<int>& vis, vector<set<int>>& adj) {
    vis[curr] = 1;
    for(auto i : adj[curr]) {
        if(!vis[i]) {
            component(i, vis, adj);
        }
    }
}

bool has_Eular_path(vector<set<int>>& adj, vector<int>& deg, int n) {
    for(int i=0; i<n; i++) {
        if(deg[i] & 1) {
            return false;
        }
    }
    
    vector<int> vis(n, 0);
    component(0, vis, adj);
    
    for(int i=0; i<n; i++) {
        if(deg[i] != 0 && !vis[i]) {
            return false;
        }
    }
    
    return true;
}

vector<int> path;
void find_path(int curr, vector<set<int>>& adj, vector<int>& deg) {
    while(deg[curr]) {
        int next = *adj[curr].begin();
        adj[curr].erase(next);
        adj[next].erase(curr);
        
        deg[curr]--;
        deg[next]--;
        
        find_path(next, adj, deg);
    }
    
    path.push_back(curr);
}

void solve() {
    int n, m;
    cin>>n>>m;
    
    vector<set<int>> adj(n);
    vector<int> deg(n);
    
    for(int i=0; i<m; i++) {
        int u, v;
        cin>>u>>v;
        
        u--;
        v--;
        
        adj[u].insert(v);
        adj[v].insert(u);
        
        deg[u]++;
        deg[v]++;
    }
    
    if(!has_Eular_path(adj, deg, n)) {
        cout<<"IMPOSSIBLE"<<endl;
        return;
    } 
    
    find_path(0, adj, deg);
    
    while(!path.empty()) {
        cout<<path.back() + 1<<" ";
        path.pop_back();
    }
}

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
    #endif
    
    int t = 1;
    while(t--) {
        solve();
    }
    
    return 0;
}
