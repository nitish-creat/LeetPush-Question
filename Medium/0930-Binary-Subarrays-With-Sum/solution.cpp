class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int pre = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(auto i : nums){
            pre += i;
            int prevele = pre - k;
            count += mpp[prevele];
            mpp[pre]++;
        }

        return count;
    }
};