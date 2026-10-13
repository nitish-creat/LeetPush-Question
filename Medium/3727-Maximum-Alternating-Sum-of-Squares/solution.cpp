class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end(),[](int a ,int b){
            return abs(a) < abs(b);
        });
        long long mini = 0;
        
        for(int i = 0; i<n/2; i++){
            mini += 1ll* nums[i] * nums[i];;
        }
        long long maxi = 0;
        for(int i = n/2; i< n; i++){
            maxi +=1ll * nums[i] * nums[i];
        }


        return abs(maxi - mini);
    }
};