class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin() , nums.end());
        int n = nums.size();
        int med = nums[n/2];
        int count = 0;
        for(auto &i : nums){
            count += abs(i-med);
        }

        return count;   
    }
};