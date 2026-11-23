class Solution {
public:
    typedef pair<int,int> p;

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        priority_queue<p, vector<p> , greater<p>> pq;
        vector<int> temp(n+1, INT_MAX);
        unordered_map<int,vector<pair<int,int>>> mp;

        for(int i = 0;i<times.size(); i++){
            int node = times[i][0];
            int neigh = times[i][1];
            int cost = times[i][2];
            mp[node].push_back({neigh ,cost});
        }
        temp[k] = 0;
        pq.push({0, k});
        temp[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int cost = pq.top().first;
            pq.pop();

            if(cost > temp[node]) continue;
            for(auto &i : mp[node]){
                int neigh = i.first;
                int dis = i.second;

                if(dis + cost < temp[neigh]){
                    temp[neigh] = dis +cost;
                    pq.push({cost + dis , neigh});
                }
            }
        }


        int ans = INT_MIN;
        for(auto &i : temp){
            if(i == INT_MAX) return -1;
            ans = max(i , ans);
        }
        return ans;
    }
};