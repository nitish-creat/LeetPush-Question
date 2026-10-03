class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = 1;
        int ans = 0;
        while(right < nums.size()){
            if(left == right){
                right++;
                continue;
            }
            int diff = nums[right] - nums[left];
            if(diff == k){
                int leftval = nums[left];
                int rightval = nums[right];
                int leftcount = 0;
                int rightcount = 0;
                while(left < nums.size() && leftval == nums[left]){
                    leftcount++;
                    left++;
                }
                while(right < nums.size() && rightval == nums[right]){
                    rightcount++;
                    right++;
                }
                ans += leftcount * rightcount;
            }
            else if(diff < k) right++;
            else left++;
        }

        return ans;
    }
};