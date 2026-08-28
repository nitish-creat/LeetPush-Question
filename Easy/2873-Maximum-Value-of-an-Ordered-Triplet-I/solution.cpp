class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n) , right(n);
        
        left[0] = nums[0];
        for(int i = 1;i<n; i++){
            left[i] = max(left[i-1], nums[i]);
        }
        right[n-1] = nums[n-1];
        for(int i = n-2;i>=0; i--){
            right[i] = max(nums[i] , right[i+1]);
        }

        long long maxi = 0;
        for(int i= 1;i<n-1;i++){
            long long val = 1ll * ( left[i-1] - nums[i]) * right[i+1];
            maxi = max(val , maxi);
        }

        return maxi;
    }
};