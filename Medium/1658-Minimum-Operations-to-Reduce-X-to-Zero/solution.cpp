class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size();
        int total = 0;
        for(auto &i : nums){
            total += i;
        }

        int target =total-x;
        if(target == 0) return n;

        int right = 0;
        int left = 0;
        int sum  =0;
        int ans = -1;
        while(right < n){
            sum += nums[right];
            while(left <= right && sum > target){
                sum -= nums[left++];
            }
            if(target == sum){
                ans = max(ans , right - left+1);
            }

            right++;
        }

        if(ans == -1) return -1;
        return n - ans;
    }
};