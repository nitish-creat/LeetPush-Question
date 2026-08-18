class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int left = 0;
        int right = k;
        unordered_map<int,int> mp;
        while(right <= nums.size()){
            unordered_set<int> temp;
            for(int i = left ; i<right; i++){
                temp.insert(nums[i]);
            }
            for(auto &i : temp){
                mp[i]++;
            }
            left++;
            right++;
        }
        int ans = -1;
        for(auto &i : mp){
            if(i.second ==1){
                ans = max(ans , i.first);
            }
        }

        return ans;
    }
};