class Solution {
public:
    bool isPossibleDivide(vector<int>& nums, int k) {
        if(nums.size() % k != 0) return false;
        unordered_map<int,int> mp;

        
        for(auto &i : nums) mp[i]++;
        sort(nums.begin() , nums.end());

        for(auto &i : nums){
            if(mp.find(i) == mp.end()) continue;
            int j = 0;
            while(j < k){
                if(mp.find(i + j) == mp.end()) return false;
                mp[i + j]--;
                if(mp[i + j] == 0) mp.erase(i+j );
                j++;
            }
        }

        return true;
    }
};