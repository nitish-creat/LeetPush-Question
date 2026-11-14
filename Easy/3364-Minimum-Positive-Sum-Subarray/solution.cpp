class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int ans = INT_MAX;
        
        for(int i = 0;i<nums.size(); i++){
            int sum = 0;
            for(int j = i; j<nums.size();j++){
                int size = j - i+1;
                sum += nums[j];
                if(size >= l && size <= r){
                    if(sum > 0 && ans > sum){
                        ans = sum;
                    }
                }
            }
        }

        return ans == INT_MAX ? -1 : ans;
    }
};