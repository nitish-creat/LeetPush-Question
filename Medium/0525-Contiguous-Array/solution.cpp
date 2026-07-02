class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int prefix = 0;
        unordered_map<int,int>mpp;
        for(int i = 0;i<nums.size();i++){
           if(nums[i] == 0) nums[i] = -1; 
        }
        int count = 0;
        mpp[0] = -1;
        for(int i =0;i<nums.size();i++){
            prefix += nums[i];
            
            if(mpp.count(prefix)){
                count = max(count , i - mpp[prefix]);
            }
            else{
                mpp[prefix] = i;
            }
        
        }

        return count;
    }
};