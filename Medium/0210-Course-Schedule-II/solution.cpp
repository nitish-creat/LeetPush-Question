class Solution {
public:
    bool dfs(vector<vector<int>> &adj , int u , stack<int> &st, vector<bool>&vis,vector<bool> &inrec){
        vis[u] = true;
        inrec[u] = true;
        for(auto &i : adj[u]){
            if(!vis[i] && dfs(adj , i , st , vis,inrec)) return true;
            if(inrec[i]) return true;
        }

        st.push(u);
        inrec[u] = false;
        return false;
    }
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<vector<int>> adj(n);
        vector<bool> vis(n,false);
        vector<bool> inrec(n,false);
        vector<int> ans;
        for(auto &i : pre){
            adj[i[1]].push_back(i[0]);
        }

        stack<int> st;
        for(int i =0;i<n ; i++){
            if(!vis[i]){
                if(dfs(adj,i , st,vis, inrec)) return {};
            }
        }

        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }

        return ans;
    }

};