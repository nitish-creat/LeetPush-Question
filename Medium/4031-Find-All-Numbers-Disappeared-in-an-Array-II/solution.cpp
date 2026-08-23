class Solution {
public:
    vector<vector<int>> findDisappearedNumbers(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        for(auto &i : nums){
            if(i < lower) continue;
            if(i > upper) break;
            if(lower < i){
                ans.push_back({lower , i -1});
            }
            lower = i+1;
        }
        if(lower <= upper){
            ans.push_back({lower , upper});
            lower = upper;
        }
        return ans;
    }
};