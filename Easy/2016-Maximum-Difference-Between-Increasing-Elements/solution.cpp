class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini = nums[0];
        int maxi = -1;
        for(int i = 1;i<nums.size(); i++){
            mini = min(mini , nums[i]);
            maxi = max(maxi , nums[i]-mini);
        }
        return (maxi == 0)? -1 : maxi;
    }
};