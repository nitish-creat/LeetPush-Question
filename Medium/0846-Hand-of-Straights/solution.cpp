class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int k) {
        if(hand.size() % k != 0) return false;
        unordered_map<int,int> mp;
        for(auto &i : hand){
            mp[i]++;
        }
        sort(hand.begin() , hand.end());
        int count = 0;
        for(auto &i : hand){
            if(mp.find(i) == mp.end()) continue;
            int j = 0;
            while(j < k){
                if(mp.find(i + j) == mp.end()) return false;
                mp[i+j]--;
                if(mp[i+j] == 0) mp.erase(i+j);
                j++;
            }
        }
        return true;
    }
};