#include <bits/stdc++.h>
using namespace std;
 
struct UnionFind {
    vector<int> par;
    vector<int> size;
    UnionFind(int n) {
        par.resize(n);
        size.resize(n,1);
        for(int i = 0; i < n; i++) {
            par[i] = i;
        }
    }
    int find(int x) {
        if(par[x] == x) {
            return x;
        }
        return par[x] = find(par[x]);
    }
    bool same(int x, int y) {
        return find(x) == find(y);
    }
    int consize(int x) {
        return size[find(x)];
    }
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if(x == y) {
            return false;
        }
        if(size[x] > size[y]) {
            swap(x,y);
        }
        par[x] = y;
        size[y] += size[x];
        return true;
    }
};

int main() {
    int n;
    cin>>n;
    
    UnionFind uf(n);
    
    return 0;
}
