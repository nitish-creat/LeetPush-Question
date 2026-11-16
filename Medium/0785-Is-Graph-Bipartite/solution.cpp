class Solution {
public:
    bool dfs(vector<vector<int>>&adj , int curr, vector<int>&color , int currcolor){
        color[curr] = currcolor;

        for(auto &i : adj[curr]){
            if(color[i] == color[curr]) return true;
            if(color[i] == -1 && dfs(adj, i ,color, 1-currcolor)) return true;
        }

        return false;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> color(graph.size(), -1);

        for(int i = 0;i<graph.size(); i++){
            if(color[i] == -1 && dfs(graph , i, color ,0)) return false;
        }

        return true;
    }
};