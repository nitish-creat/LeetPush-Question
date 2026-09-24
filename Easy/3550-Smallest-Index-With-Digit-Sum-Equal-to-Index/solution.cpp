class Solution {
public:
    int check(int n){
        string s= to_string(n);
        int sum = 0;
        for(auto &i:s){
            sum += i - '0';
        }
        return sum;
    }
    int smallestIndex(vector<int>& nums) {
        for(int i = 0;i<nums.size(); i++){
            if(check(nums[i]) == i) return i;
        }

        return -1;
    }
};