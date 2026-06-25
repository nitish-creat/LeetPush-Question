class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        map<int,int> mp;
        mp[0] = 1;
        int count = 0;
        int preSum = 0;
        for(int i = 0;i<nums.size();i++){
            preSum += nums[i];
            int remove = preSum - k;
            count+= mp[remove];
            mp[preSum]++;

        }
        return count;
    }
};