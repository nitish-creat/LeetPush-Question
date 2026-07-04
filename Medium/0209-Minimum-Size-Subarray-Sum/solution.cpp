class Solution {
public:
    int minSubArrayLen(int k, vector<int>& nums) {
        int left = 0;
        int right = 0;
        int len = INT_MAX;
        int sum = 0;
        while(right < nums.size()){
            sum += nums[right];
            while(left < nums.size() && sum >= k ){
                len = min(len , right - left +1);
                sum -=  nums[left];
                left++;
            }

            right++;
        }

        return (len == INT_MAX)? 0 : len;
    }
};