struct SegTree {
    vector<int> data;

    SegTree(int n) {
        data.resize(4 * n + 1);
    }

    void build(int idx, int low , int high, vector<int>& arr) {
        if(low == high) {   
            data[idx] = arr[low];
            return;
        }
        
        int mid = (low + high) / 2;
        build(2*idx + 1, low, mid, arr);
        build(2*idx + 2, mid + 1, high, arr);
        
        data[idx] = min(data[2*idx + 1], data[2*idx + 2]);
    }

    int query(int idx, int low, int high, int l, int r) {
        // no overlap
        if(l > high || r < low)     
            return INT_MAX;
        
        // complete overlap
        if(low >= l && high <= r)   
            return data[idx];
        
        int mid = (low + high) / 2;
        int left = query(2*idx + 1, low, mid, l, r);
        int right = query(2*idx + 2, mid + 1, high, l, r);
        
        return min(left, right);
    }

    void update(int idx, int low, int high, int i, int val) {
        if(low == high) {
            data[idx] = val;
            return;
        }
        
        int mid = (low + high) >> 1;
        if(i <= mid)    update(2*idx + 1, low, mid, i, val);
        else    update(2*idx + 2, mid+1, high, i, val);
        
        data[idx] = min(seg[2*idx + 1], seg[2*idx + 2]);
    }
};
