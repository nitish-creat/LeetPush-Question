class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int> , vector<pair<double,int>>, greater<pair<double,int>>> pq;
        int n = points.size();
        for(int i =0;i<n ; i++){
            int first = points[i][0];
            int second = points[i][1];
            int add = (first*first) + (second*second);
            pq.push({sqrt(add) , i});
        }
        vector<vector<int>> ans;
        while(k > 0){
            auto i = pq.top();
            pq.pop();
            ans.push_back(points[i.second]);
            k--;
        }

        return ans;
    }
};