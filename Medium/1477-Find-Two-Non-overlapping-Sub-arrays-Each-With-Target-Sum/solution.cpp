class Solution {
public:
    int minSumOfLengths(vector<int>& nums, int target) {
        
        int left = 0;
        int right = 0;
        vector<int> mintillind(nums.size() , INT_MAX);
        int res = INT_MAX;
        int mini = INT_MAX;
        int currsum = 0;
        while(right < nums.size()){
            currsum += nums[right];
            while(currsum > target){
                currsum -= nums[left++];
            }

            if(currsum == target){
                int len = right - left+1;
                if( left > 0 && mintillind[left-1] != INT_MAX){
                    res = min(res , len + mintillind[left-1]);
                }
                mini = min(len , mini);
            }

            mintillind[right] = mini;
            right++;
        }

        return res == INT_MAX? -1 : res;
    }
};