class Solution {
public:
    vector<int> parent;
    vector<int> rank;
    int find(int x){
        if(parent[x] == x) return x;

        return parent[x] = find(parent[x]);
    }
    void uni(int a , int b){
        int parenta = find(a);
        int parentb = find(b);
        
        if(parenta == parentb) return;

        if(rank[parenta] > rank[parentb]){
            parent[parentb] = parenta;
        }
        else if(rank[parentb] > rank[parenta]){
            parent[parenta] = parentb;
        }
        else{
            parent[parentb] = parenta;
            rank[parenta]++;
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        rank.resize(n+1);
        vector<int> ans(2);
        for(int i = 0;i<n; i++){
            parent[i] = i;
            rank[i] = 0;
        }

        for(auto &i : edges){
            if(i[0] < i[1]){
                if(find(i[0]) == find(i[1])){
                    ans[0]= i[0];
                    ans[1] = i[1];
                }
                uni(i[0] , i[1]);
            }
        }

        return ans;
    }
};