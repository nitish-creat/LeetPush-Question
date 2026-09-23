class Solution {
public:
    vector<int> twoSum(vector<int>& num, int target) {
        vector<int> ans;
        int left = 0;
        int right = num.size() -1;
        while(left < right){
            int sum = num[left] + num[right];
            if(sum == target){
                ans.push_back(left+1);
                ans.push_back(right+1);
            } 
            if(sum > target) right--;
            else{
                left++;
            }
        }

        return ans;
    }
};