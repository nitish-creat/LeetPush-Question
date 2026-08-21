class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n = nums.size();
        bool inc = false;
        bool dec = false;
        if(n <= 1) return true;
        for(int i = 1;i<n ;i++){
            if(nums[i-1] >= nums[i]){
                inc = true;
            }
            else{
                inc = false;
                break;
            }
        }
        for(int i = 1;i<n ;i++){
            if(nums[i-1] <= nums[i]){
                dec = true;
            }
            else{
                dec = false;
                break;
            }
        }

        if(inc || dec) return true;
        return false;

    }
};