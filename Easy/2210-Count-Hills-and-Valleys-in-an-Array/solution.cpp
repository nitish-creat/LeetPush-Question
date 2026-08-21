class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int left = nums[0];
        for(int i = 0;i<n-1;i++){
            if(nums[i] == nums[i+1]) continue;
            if(left < nums[i] && nums[i] > nums[i+1] ||
            left > nums[i] && nums[i+1] > nums[i]){
                count++;
                left = nums[i];
            }
        }

        return count;
    }
};