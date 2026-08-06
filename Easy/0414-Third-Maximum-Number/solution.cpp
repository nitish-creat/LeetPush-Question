class Solution {
public:
    int thirdMax(vector<int>& nums) {
        sort(nums.rbegin() , nums.rend());
        
        int ele = 0;
        int count = 1;
        for(int i = 1;i<nums.size(); i++){
            if(nums[i] != nums[i-1]){
                ele = nums[i];
                count++;
                if(count == 3) return ele;
            }
        }
        return nums[0];
    }
};