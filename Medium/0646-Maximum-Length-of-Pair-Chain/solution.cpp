class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin() , pairs.end() , [](auto &a , auto &b){
            return a[1] < b[1];
        });
        int last = INT_MIN;
        int count = 0;
        for(int i = 0;i<pairs.size(); i++){
            if(last < pairs[i][0]){
                count++;
                last = pairs[i][1];
            }
        }

        return count;
    }
};