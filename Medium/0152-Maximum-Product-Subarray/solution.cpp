class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxPro = INT_MIN;
        int prefix = 1;
        int suffix = 1;
        for(int i=0;i<nums.size();i++){
            if(prefix == 0) prefix = 1;
            if(suffix == 0) suffix = 1;

            prefix *= nums[i];
            suffix *= nums[nums.size() - i -1];

            maxPro = max(maxPro,max(prefix,suffix));
        }


        return maxPro;
    }
};