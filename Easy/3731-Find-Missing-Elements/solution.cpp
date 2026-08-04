class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> ans;
        unordered_set<int> s;
        for(auto &i : nums){
            s.insert(i);
        }

        sort(nums.begin(),nums.end());
        int maxi = nums[nums.size()-1];
        int mini = nums[0];
        vector<int> temp;
        for(int i = mini ; i<maxi ;i++){
            temp.push_back(i);
        }
        for(int i = 0;i<temp.size();i++){
            if(s.find(temp[i]) == s.end()){
                ans.push_back(temp[i]);
            }
        }

        return ans;
    }
};