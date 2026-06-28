class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long ans = 0;
        for(int i= 0;i<nums.size();i++){
            long long mini = nums[i];
            long long maxi = nums[i];
            for(int j = i+1 ;j<nums.size(); j++){
                mini = min(mini , (long long)nums[j]);
                maxi = max(maxi , (long long)nums[j]);
                ans += maxi - mini;
            }
        }

        return ans;
    }
};