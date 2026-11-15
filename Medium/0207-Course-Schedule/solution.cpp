class Solution {
public:
    bool check(vector<vector<int>> &adj, int u, vector<bool>&vis, vector<bool>&inrec){
        vis[u] = true;
        inrec[u] = true;

        for(auto &i : adj[u]){
            if(!vis[i] && check(adj, i, vis, inrec)) return true;

            if(inrec[i]) return true;
        }

        inrec[u] = false;
        return false;
    }
    bool canFinish(int n, vector<vector<int>>& pre) {
        vector<bool> vis(n,false);
        vector<bool> inrec(n, false);
        vector<vector<int>> adj(n);

        for(auto &i : pre){
            adj[i[1]].push_back(i[0]);
        }
        for(int i = 0;i<n; i++){
            if(!vis[i] && check(adj ,i,vis,inrec)) return false;
        }

        return true;
    }
};