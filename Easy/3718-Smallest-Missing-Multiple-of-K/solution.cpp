class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;
        for(auto &i:nums){
            st.insert(i);
        }
        bool check = false;
        int i = 1;
        int ans = -1;
        while(!check){
            if(!st.count(k*i)){
                ans = k*i;
                check = true;
            }
            i++;
        }

        return ans;
    }
};