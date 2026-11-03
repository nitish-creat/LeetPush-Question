class Solution {
public:
    int minMoves(vector<int>& nums) {
        int move= 0;
        int maxi = INT_MIN;
        for(auto &i : nums){
            maxi = max(maxi , i);
        }

        for(auto &i : nums){
            move += maxi - i;
        }

        return move;
    }
};