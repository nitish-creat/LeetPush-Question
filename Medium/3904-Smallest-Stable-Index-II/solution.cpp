class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> maxi(n), mini(n);
        maxi[0] = nums[0];
        for(int i=1;i<n;i++){
            maxi[i] = max(nums[i],maxi[i-1]);
        }
        mini[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            mini[i] = min(mini[i+1],nums[i]);
        }

        for(int i=0 ;i<nums.size();i++){
            if(maxi[i] - mini[i] <= k){
                return i;
            }
        }
        
        return -1;
    }
};