class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        unordered_map<int,int> freq;
        for(auto i : nums){
            freq[i]++;
        }
        vector<pair<int,int>> vec(freq.begin(),freq.end());

        sort(vec.begin(),vec.end(),[](pair<int,int>&a , pair<int,int>&b){
            return a.second > b.second;
        }); 
        for(int i = 0 ;i < k;i++){
            ans.push_back(vec[i].first);
        }
        return ans;

    }
};