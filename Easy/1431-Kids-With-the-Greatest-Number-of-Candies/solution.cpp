class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int e) {
        vector<bool> ans;
        int maxi = 0;
        for(auto &i : candies){
            maxi = max(maxi,i);
        }
        for(auto &i : candies){
            if(i + e >= maxi){
                ans.push_back(true);
            }
            else{
                ans.push_back(false);
            }
        }

        return ans;
    }
};