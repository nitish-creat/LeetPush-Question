class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int ind = 0;
        int n = tasks.size();
        for(auto &i : tasks){
            i.push_back(ind++);
        }

        sort(tasks.begin() , tasks.end());
        vector<int> ans;
        priority_queue<P, vector<P>, greater<P>> pq;
        long long curr = 0;
        int idx = 0;

        while(idx < n || !pq.empty()){
            if(pq.empty() && curr <= tasks[idx][0]){
                curr = tasks[idx][0];
            }

            while(idx < n && curr >= tasks[idx][0]){
                pq.push({tasks[idx][1] , tasks[idx][2]});
                idx++;
            }
            auto task = pq.top();
            pq.pop();
            curr += task.first;
            ans.push_back(task.second);
        }

        return ans;
    }
};