class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int c = INT_MIN;
        for(auto i : nums){
            if(i == 1) count++;
            else count = 0;
            c =  max(c,count);
        }
        return c;
    }
};