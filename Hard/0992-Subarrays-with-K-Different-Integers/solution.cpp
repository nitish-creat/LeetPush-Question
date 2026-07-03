class Solution {
public:
    int subarray(vector<int>&arr , int k){
        unordered_map<int,int> mp;
        int left = 0;
        int right = 0;
        int count = 0;
        while(right < arr.size()){
            mp[arr[right]]++;
            while(mp.size() > k){
                mp[arr[left]]--;
                if(mp[arr[left]] == 0){
                    mp.erase(arr[left]);
                }
                left++;
            }

            count += right - left+1;
            right++;
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarray(nums,k) - subarray(nums , k-1);
    }
};