class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        priority_queue<P , vector<P>, greater<P>> pq;
        int n = nums1.size();
        int m = nums2.size();

        vector<vector<int>> ans;
        set<pair<int,int>> vis;

        int sum = nums1[0] + nums2[0];
        pq.push({sum , {0,0}});
        vis.insert({0,0});

        while(k--&& !pq.empty()){
            auto temp = pq.top();
            pq.pop();
            int i = temp.second.first;
            int j = temp.second.second;

            ans.push_back({nums1[i] , nums2[j]});

            if(i +1 < n && !vis.count({i+1,j})){
                pq.push({nums1[i+1] + nums2[j] , {i+1 , j}});
                vis.insert({i+1,j});
            }
            if(j +1 < m && !vis.count({i , j+1})){
                pq.push({nums1[i] + nums2[j+1] ,{i , j+1}});
                vis.insert({i , j+1});
            }
        }

        return ans;
    }
};