class Solution {
public:
    void combine(int ind, vector<int>&arr, vector<vector<int>>&temp,vector<int>&dum, int x){
        if(ind == arr.size()){
            if(x == 0){
                temp.push_back(dum);
            }
            return;
        }
        if(arr[ind] <= x){
            dum.push_back(arr[ind]);
            combine(ind,arr,temp,dum,x-arr[ind]);
            dum.pop_back();
        }
        combine(ind+1,arr,temp,dum,x);
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> temp;
        vector<int> dum;
        combine(0,candidates,temp,dum,target);
        return temp;
    }
};