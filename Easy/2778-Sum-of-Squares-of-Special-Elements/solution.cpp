class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        long long sum = 0;
        int n = nums.size();
        for(int i = 0;i<nums.size();i++){
            if(n % (i+1) == 0){
                int ele = nums[i] * nums[i];
                sum += ele;
            }
        }

        return sum;
    }
};