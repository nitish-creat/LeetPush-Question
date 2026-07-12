class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> temp = arr;
        unordered_map<int,int> mp;
        sort(arr.begin(),arr.end());
        int rank =1;
        for(int i = 0;i<arr.size() ; i++){
            if(mp.find(arr[i]) == mp.end()){
                mp[arr[i]] = rank++;
            }
        }
        vector<int> ans(arr.size());
        for(int i =0;i<temp.size() ; i++){
            ans[i] = mp[temp[i]];
        }

        return ans;
    }
};