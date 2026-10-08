class Solution {
public:
    string removeOuterParentheses(string s) {
        int left = 0;
        int depth = 0;
        unordered_set<int>st;
        for(int i = 0;i<s.size();i++){
            if(depth == 0){
                left = i;
            }
            if(s[i] == '('){
                depth++;
            }
            else{
                depth--;
            }
            if(depth == 0){
                st.insert(i);
                st.insert(left);
            }
        }

        string res = "";
        for(int i = 0;i<s.size(); i++){
            if(st.count(i)) continue;
            res += s[i];
        }

        return res;
    }
};