class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& arr) {
        int count = 1;
        sort(arr.begin(),arr.end(),[](auto &a , auto &b){
            return a[1] < b[1];
        });
        pair<int,int> prev = {arr[0][0],arr[0][1]};
        for(int i = 1;i<arr.size(); i++){
            pair<int,int> curr = {arr[i][0], arr[i][1]};
            if(prev.second <= curr.first){
                count++;
                prev = curr;
            }
        }

        return arr.size() - count;
    }
};