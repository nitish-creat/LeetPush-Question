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
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n-1) return -1;
        parent.resize(n);
        rank.resize(n,0);

        for(int i = 0;i<n; i++){
            parent[i] =i;
        }
        int compo = n;
        for(auto &vec : connections){
            if(find(vec[0]) != find(vec[1])){
                uni(vec[0] , vec[1]);
                compo--;
            }
        }

        return compo - 1;
    }
};