class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        unordered_map<int,int> mpp;
        for(int i=0 ;i<arr.size();i++){
            int rem = target - arr[i];
            if(mpp.find(rem) != mpp.end()){
                return {mpp[rem], i};
            }
            mpp[arr[i]] = i;
        }
        return {};
    }
};