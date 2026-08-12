class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        int res = 0;
        int left = 0, right = 0;
        while(right < nums.size()){
            mp[nums[right]]++;
            while(left < right && mp[nums[right]] > k){
                mp[nums[left]]--;
                left++;
            }
            res = max(res,right -left +1);
            right++;
            
        }
        return res;
    }
};