void solve() {
    int n, m;
    cin>>n>>m;

    vector<vector<pair<int, int>>> adj(n+1);
    for(int i=0, u, v, wt; i<m; i++) {
        cin>>u>>v>>wt;

        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }

    vector<int> dist(n+1, INF);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push({0, 1});
    dist[1] = 0;

    while(pq.size()) {
        int curr = pq.top().second;
        int curr_dist = pq.top().first;
        pq.pop();

        for(auto &i : adj[curr]) {
            if(curr_dist + i.second < dist[i.first]) {
                dist[i.first] = curr_dist + i.second;
                pq.push({dist[i.first], i.first});
            }
        }
    }

    print(dist);
}
