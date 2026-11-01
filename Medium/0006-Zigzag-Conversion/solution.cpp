class Solution {
public:
    string convert(string s, int numRows) {
        string ans;
        // if(s.size() ==1) return s;
        if(numRows == 1 || s.size() <= numRows) return s;
        int i=0;
        bool dir = false;
        vector<string> rows(numRows);
        for(auto c : s){
            rows[i] += c;
            if(i == 0 || i == numRows -1){
                dir = !dir;
            }
            i += dir ? 1 : -1;
        }
        for(auto j : rows){
            ans += j;
        }
        return ans;
    }
};