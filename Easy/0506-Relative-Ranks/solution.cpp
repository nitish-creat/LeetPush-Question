class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<string> ans(score.size());
        priority_queue<pair<int,int>> pq;
        for(int i = 0;i <score.size(); i++){
            pq.push({score[i] , i});
        }
        int i = 0;
        while(!pq.empty()){
            auto ele = pq.top();
            pq.pop();
            if(i == 0){
                ans[ele.second] = "Gold Medal";
            }
            else if(i == 1){
                ans[ele.second] = "Silver Medal";
            }
            else if( i == 2){
                ans[ele.second] = "Bronze Medal";
            }
            else{
                ans[ele.second] = to_string(i+1);
            }
            i++;
        }
        return ans;
    }
};