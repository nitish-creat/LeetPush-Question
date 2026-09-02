class Solution {
public:
    string removeStars(string s) {
        stack<int> st;
        for(auto &i : s){
            if(i == '*') st.pop();
            else st.push(i);
        }

        string ans = "";
        int n = st.size();
        while(n--){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};