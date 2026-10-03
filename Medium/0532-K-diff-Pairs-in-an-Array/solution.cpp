class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans= 0;
        int left = 0;
        int right = 1;
        while(right < nums.size()){
            if(left == right){
                right++;
                continue;
            }
            int diff = nums[right] - nums[left];
            if(diff == k){
                ans++;
                int leftval = nums[left];
                int rightval= nums[right];

                while(left <nums.size() && nums[left] == leftval) left++;
                while(right < nums.size() && nums[right] == rightval) right++;
            }
            else if(diff < k) right++;
            else left++;
        }

        return ans;
    }
};