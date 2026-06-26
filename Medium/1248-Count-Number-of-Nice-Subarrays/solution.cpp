class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        vector<int> temp;
        for(auto i:nums){
            if(i%2==0){
                temp.push_back(0);
            }
            else{
                temp.push_back(1);
            }
        }
        int pre = 0;
        int count = 0;
        unordered_map<int,int> mpp;
        mpp[0] = 1;
        for(auto i : temp){
            pre += i;
            int prevele = pre - k;
            count += mpp[prevele];
            mpp[pre]++;
        }

        return count;
    }
};