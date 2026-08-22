class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        unordered_map<int,int> won;
        unordered_map<int, int> lost;
        for(auto &i : matches){
            won[i[0]]++;
            lost[i[1]]++;
        }
        vector<int> win;
        vector<int> lose;
        for(auto &i : won){
            if(lost.find(i.first) != lost.end()){
                if(lost[i.first] == 1){
                    lose.push_back(i.first);
                }
            }
            else win.push_back(i.first);
        }
        for(auto &i : lost){
            if(i.second == 1 && !won.count(i.first)) lose.push_back(i.first);
        }
        sort(win.begin() , win.end());
        sort(lose.begin() , lose.end());
        return {win,lose};
    }
};