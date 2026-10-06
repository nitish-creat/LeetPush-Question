class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int> st;
        unordered_set<int> stt;
        for(int i = 0;i<s.size(); i++){
            if(s[i] == '('){
                st.push(i);
            }
            else if(s[i] == ')'){
                if(!st.empty()) st.pop();
                else{
                    stt.insert(i);
                }
            }
        }
        string res = "";
        while(!st.empty()){
            stt.insert(st.top());
            st.pop();
        }
        for(int i = 0;i<s.size(); i++){
            if(!stt.count(i)){
                res += s[i];
            }
        }
        return res;
    }
};