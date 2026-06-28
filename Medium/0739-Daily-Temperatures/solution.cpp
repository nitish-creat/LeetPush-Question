class Solution {
public:
    vector<int> nge(vector<int>&arr){
        stack<int> st;
        int n = arr.size();
        vector<int> ans(n);
        for(int i = n-1; i >=0 ;i--){
            while(!st.empty() && arr[st.top()] <= arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? -1: st.top();
            st.push(i);
        }

        return ans;
    }
    vector<int> dailyTemperatures(vector<int>& temp) {
        vector<int> next = nge(temp);
        vector<int> ans(temp.size());
        for(int i = 0;i<temp.size();i++){
            ans[i] = (next[i] == -1)? 0 : next[i]-i;
        }

        return ans;
    }
};