class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;
        string res = "";
        for(auto &i:s){
            if(i == '(') st.push(res.size());
            else if(i==')'){
                int left = st.top();
                st.pop();
                reverse(res.begin()+left, res.end());
            }
            else res += i;
        }

        return res;
    } 
};