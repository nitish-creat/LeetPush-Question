class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int mini = 0;
        for(auto &i : nums){
            if(i < k) mini++;
        }
        return mini;
    }
};