class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& costs) {
        vector<pair<int , pair<int,int>>> temp;
        for(int i = 0;i<costs.size(); i++){
            temp.push_back({costs[i][0] - costs[i][1] , {costs[i][0] , costs[i][1]}});
        }
        sort(temp.begin(),temp.end());
        int n = costs.size();
        int ans = 0;
        for(int i = 0;i<n/2; i++){
            ans += temp[i].second.first;
        }
        for(int i =n/2 ; i<n; i++){
            ans += temp[i].second.second;
        }

        return ans;
    }
};