class Solution {
public:
    priority_queue<pair<int,int>> maxi;
    priority_queue<pair<int,int>, vector<pair<int,int>> ,greater<pair<int,int>>> mini;
    unordered_map<int,int> mp;
    vector<bool> dead;
    int maxiSz = 0, miniSz = 0;

    void prune(){
        while(!maxi.empty() && dead[maxi.top().second]) maxi.pop();
        while(!mini.empty() && dead[mini.top().second]) mini.pop();
    }
    void balance(){
        if(maxiSz > miniSz+1){
            auto ele = maxi.top();
            mini.push(ele);
            mp[ele.second] = 1;
            maxi.pop();
            maxiSz--;
            miniSz++;
        }
        else if(maxiSz < miniSz){
            auto ele = mini.top();
            maxi.push(ele);
            mp[ele.second] = 0;
            mini.pop();
            miniSz--;
            maxiSz++;
        }
        prune();
    }
    void remove(int n){
        dead[n] = true;
        if(mp[n] == 0) maxiSz--;
        else miniSz--;
        prune();
        balance();
    }
    void add(pair<int,int> &i){
        if(maxiSz == 0 || maxi.top().first > i.first){
            maxi.push(i);
            mp[i.second] = 0;
            maxiSz++;
        }
        else{
            mini.push(i);
            mp[i.second] = 1;
            miniSz++;
        }
        balance();
    }
    double median(){
        if(maxiSz == miniSz){
            return ((double)maxi.top().first + mini.top().first) / 2;
        }
        return maxi.top().first;
    }
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        maxi = {};
        mini = {};
        mp.clear();
        dead.assign(nums.size(), false);
        maxiSz = miniSz = 0;

        for(int i = 0; i < k; i++){
            pair<int,int> p = {nums[i], i};
            add(p);
        }

        int left = 0;
        int right = k;
        vector<double> ans;
        ans.push_back(median());

        while(right < nums.size()){
            remove(left++);
            pair<int,int> p = {nums[right], right};
            add(p);
            ans.push_back(median());
            right++;
        }
        return ans;
    }
};