class Solution {
public:
    void SubSeq(int ind,vector<int>&arr, vector<vector<int>>&temp, vector<int>&dum){
        if(ind == arr.size()){
            bool check = false;
            for(auto i : temp){
                if(i == dum){
                    check = true;
                }
            }
            if(!check){
                temp.push_back(dum);
            }
            return;
        }
        dum.push_back(arr[ind]);
        SubSeq(ind+1, arr, temp, dum);
        dum.pop_back();
        SubSeq(ind+1 , arr, temp, dum);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> temp;
        vector<int> dum;
        sort(nums.begin(),nums.end());
        SubSeq(0,nums,temp,dum);
        return temp;
    }
};