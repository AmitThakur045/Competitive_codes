struct Hashing {
    string s;  // original string
    int n;  // length of string
    int totalPrime;
    const int base = 31;
    
    vector<vector<int>> hashValue, powerOfBase;
    vector<int> primeValue = {1000000009, 100000007}; //optimal to choose largest prime no which can fit in 64 bit
    
    Hashing(string a) {
        s = a;
        n = s.size();
        totalPrime = primeValue.size();
        
        hashValue.resize(totalPrime);
        powerOfBase.resize(totalPrime);
        
        // filling the powerOfBase
        for(int i=0; i<totalPrime; i++) {
            powerOfBase[i].resize(n+1);
            powerOfBase[i][0] = 1;
            
            for(int j=1; j<=n; j++) {
                powerOfBase[i][j] = (base * powerOfBase[i][j-1]) % primeValue[i];
            }
        }
        
        // filling the hashValue of string s;
        for(int i=0; i<totalPrime; i++) {
            hashValue[i].resize(n);
            
            for(int j=0; j<n; j++) {
                hashValue[i][j] = ((s[j] - 'a' + 1) * powerOfBase[i][j]) % primeValue[i];
                hashValue[i][j] = (hashValue[i][j] + (j > 0 ? hashValue[i][j-1] : 0)) % primeValue[i];
            }
        }
    }
    
    vector<int> substringHash(int l, int r){
        vector<int> hash(totalPrime);
        for(int i = 0; i < totalPrime; i++){
            ll val1 = hashValue[i][r];
            ll val2 = l > 0 ? hashValue[i][l - 1] : 0LL;
            hash[i] = mod_mul(mod_sub(val1, val2, primeValue[i]), modinv(powerOfBase[i][l], primeValue[i]), primeValue[i]);
        }
        return hash;
    }
    
    bool compareSubstrings(int l1, int r1, int l2, int r2) {
        if(l1 > l2){
            swap(l1, l2);
            swap(r1, r2);
        }
        for(int i = 0; i < totalPrime; i++){
            ll val1 = mod_sub(hashValue[i][r1], (l1 > 0 ? hashValue[i][l1 - 1] : 0LL), primeValue[i]);
            ll val2 = mod_sub(hashValue[i][r2], (l2 > 0 ? hashValue[i][l2 - 1] : 0LL), primeValue[i]);
            if(mod_mul(val1, powerOfBase[i][l2 - l1], primeValue[i]) != val2)
                return false;
        }   
        return true;
    }
    
    void addChar(char ch) {
        s += ch;
        n += 1;
        
        for(int i=0; i<totalPrime; i++) {
            while(powerOfBase[i].size() < n) {
                powerOfBase[i].push_back((powerOfBase[i].back() * base) % primeValue[i]);
            }
        }
        
        for(int i=0; i<totalPrime; i++) {
            while(hashValue[i].size() < n) {
                if(hashValue[i].size() == 0) {
                    hashValue[i].push_back((s[0] - 'a' + 1) % primeValue[i]);
                } else {
                    int nextHash = hashValue[i].back() + ((s.back() - 'a' + 1) * powerOfBase[i].back()) % primeValue[i];
                    hashValue[i].push_back((nextHash + primeValue[i]) % primeValue[i]);
                }
            }
        }
    }  
};
