class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int m = 0, k=0;
        for(int i =0;i<n;i++){
            if(maxi < nums[i]){
                maxi = nums[i];
                m = i;
            }
            if(mini > nums[i]){
                mini = nums[i];
                k = i;
            }
        }
        int l = min(m ,k);
        int r = max(m ,k);
        
        return min({ r+1 , n-l, l +1 + n- r});
        
    }
};