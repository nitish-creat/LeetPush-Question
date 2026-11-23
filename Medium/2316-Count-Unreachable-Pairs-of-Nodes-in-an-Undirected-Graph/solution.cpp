class Solution {
public:
    vector<int> parent;
    vector<int> rank;

    int find(int u){
        if(parent[u] == u) return u;

        return parent[u] = find(parent[u]);
    }
    void uni(int x, int y){
        int parentx = find(x);
        int parenty = find(y);

        if(parentx == parenty) return;
        
        if(rank[parentx] < rank[parenty]){
            parent[parentx] = parenty;
        }
        else if(rank[parentx] > rank[parenty]){
            parent[parenty] = parentx;
        }
        else{
            parent[parenty] = parentx;
            rank[parentx]++;
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n , 0);
        unordered_map<int,int> mp;
        for(int i = 0;i<n; i++){
            parent[i] = i;
        }

        for(auto &i : edges){
            uni(i[0] , i[1]);
        }
        for(int i = 0;i< n; i++){
            int x = find(i);
            mp[x]++;
        }
        long long ans = 0;
        long long remain = n;
        for(auto &i : mp){
            int size = i.second;

            ans += size *(remain-size);
            remain -= size;
        }

        return ans ;
    }
};