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
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26, 0);

        for(int i = 0;i<26 ; i++){
            parent[i] = i;
        }
        
        for(auto &s : equations){
            if(s[1] == '='){
                uni(s[0] - 'a' , s[3]- 'a');
            }
        }

        for(auto &s : equations){
            if(s[1] != '='){
                if(find(s[0]-'a') == find(s[3] - 'a')) return false;
            }
        }

        return true;
    }
};