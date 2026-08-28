class Solution {
public:
    int convert(string s){
        return stoi(s.substr(0,2)) * 60 + stoi(s.substr(3,2));
    }
    bool haveConflict(vector<string>& event1, vector<string>& event2) {
        pair<int,int> prev = {convert(event1[0]) , convert(event1[1])};
        pair<int,int> curr = {convert(event2[0]) , convert(event2[1])};
        if(prev.second >= curr.first && curr.second >= prev.first){
            return true;
        }

        return false;
    }
};