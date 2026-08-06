class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int,int>> temp;
        for(int i = 0;i<nums.size();i++){
            temp.push_back({i , nums[i]});
        }
        sort(temp.begin() , temp.end() , [](auto &a , auto &b){
            return a.second > b.second;
        });
        temp.resize(k);
        sort(temp.begin(),temp.end());

        vector<int> ans;
        for(auto &i : temp){
            ans.push_back(i.second);
        }

        return ans;

    }
};