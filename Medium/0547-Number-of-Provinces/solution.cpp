class Solution {
public:
    void dfs(unordered_map<int,vector<int>>&adj , int u , vector<bool>&vis){
        vis[u] = true;

        for(auto &i : adj[u]){
            if(!vis[i]){
                dfs(adj , i, vis);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& arr) {
        vector<bool> vis(arr.size() , false);
        unordered_map<int,vector<int>> adj;

        for(int i = 0;i<arr.size(); i++){
            for(int j = 0;j<arr.size(); j++){
                if(arr[i][j] == 1){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count = 0;
        for(int i = 0;i<arr.size(); i++){
            if(!vis[i]){
                dfs(adj , i , vis);
                count++;
            }
        }

        return count;
    }
};