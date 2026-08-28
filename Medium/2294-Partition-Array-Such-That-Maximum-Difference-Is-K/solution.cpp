class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int mini = nums[0];
        int maxi = nums[0];
        int count = 1;
        for(int i = 1;i<nums.size(); i++){
            maxi = max(maxi , nums[i]);
            if(maxi - mini > k && nums[i-1]!=nums[i]){
                mini = nums[i];
                maxi = nums[i];
                count++;
            }
        }

        return count;
    }
};