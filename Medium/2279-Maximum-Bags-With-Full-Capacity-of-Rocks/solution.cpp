class Solution {
public:
    int maximumBags(vector<int>& cap, vector<int>& rocks, int add) {
        vector<int> need(cap.size());
        for(int i = 0;i<cap.size() ; i++){
            need[i] = cap[i] - rocks[i];
        }
        sort(need.begin(),need.end());
        int count = 0;
        for(auto &i : need){
            if(add >= i){
                count++;
                add -= i;
            }
            else break;
        }

        return count;
    }
};