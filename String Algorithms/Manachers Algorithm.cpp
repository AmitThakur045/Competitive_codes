vector<char> preProcess(string& s, int n) {
    vector<char> res;
    res.push_back('@');
    res.push_back('#');

    for(auto &i : s) {
        res.push_back(i);
        res.push_back('#');
    }
    res.push_back('$');
    return res;
}

vector<int> manachers(string &s, int n) {
    vector<char> res = preProcess(s, n);
    n = res.size();
    
    int c = 0, r = 0;
    vector<int> ans(n, 0);
    
    for(int i=1; i<n-1; i++) {
        if(i <= r) {
            ans[i] = min(r-i, ans[c - (i - c)]);
        } 
        
        while(res[i+ans[i]+1] == res[i-ans[i]-1]) {
            ans[i]++;
        }
        
        if(i + ans[i] > r) {
            c = i;
            r = ans[i]+i;
        }
    }
    
    return ans;
}
