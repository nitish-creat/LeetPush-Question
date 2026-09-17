class Solution {
public:
    bool findSubarrays(vector<int>& nums) {
        unordered_set<int> st;
        int right = 1;
        int left = 0;
        while(right < nums.size()){
            int sum = nums[left]+nums[right];
            if(st.find(sum) != st.end()) return true;
            st.insert(sum);
            left++;
            right++;
        }

        return false;
    }
};