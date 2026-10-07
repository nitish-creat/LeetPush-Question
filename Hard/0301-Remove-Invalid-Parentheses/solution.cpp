class Solution {
public:
    unordered_set<string> stt;
    unordered_set<string> vis;
    vector<string> res;
    int minInvalid(string s){
        int open = 0;
        int count = 0;
        for(auto &i :s){
            if(i == '('){
                open++;
            }
            else if(i == ')'){
                if(open > 0) open--;
                else count++;
            }
        }

        return open + count;
    }
    void solve(string s, int mini){
        if(mini < 0) return;
        if(vis.count(s)) return;
        vis.insert(s);
        if(mini == 0){
            if(minInvalid(s) == 0){
                if(!stt.count(s)){
                    res.push_back(s);
                    stt.insert(s);;
                }
            }
            return;
        }
        for(int i = 0;i<s.size(); i++){
            if(s[i] != ')' && s[i] != '(') continue;
            string left = s.substr(0,i);
            string right = s.substr(i+1);
            solve(left+right ,mini-1);
        }

        return;
    }
    vector<string> removeInvalidParentheses(string s) {
        solve(s , minInvalid(s));
        
        return res;
    }
};