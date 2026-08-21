class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> ans;
        map<int,int> mp;
        for(auto &i : arr1){
            mp[i]++;
        }
        for(int i = 0;i<arr2.size() ; i++){
            int ele = arr2[i];
            int size = mp[ele];
            while(size--){
                ans.push_back(ele);
                mp[ele]--;
                if(mp[ele] == 0) mp.erase(ele);
            }
        }
        // vector<int> remain;
        if(!mp.empty()){
            for(auto &i :mp){
                int size = i.second;
                while(size--){
                    ans.push_back(i.first);
                }
            }
        }
        // sort(remain.begin() , remain.end());
        // for(auto &i:remain){
        //     ans.push_back(i);
        // }
        return ans;
    }
};