class Solution {
public: 
    void SubSeq(int ind,vector<int>&arr, vector<vector<int>>&temp, vector<int>&dum){
        if(ind == arr.size()){
            temp.push_back(dum);
            return;
        }
        dum.push_back(arr[ind]);
        SubSeq(ind+1, arr, temp, dum);
        dum.pop_back();
        SubSeq(ind+1 , arr, temp, dum);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> temp;
        vector<int> dum;
        SubSeq(0,nums,temp,dum);
        return temp;
    }
};