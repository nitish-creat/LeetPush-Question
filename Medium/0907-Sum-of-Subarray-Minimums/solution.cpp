class Solution {
public:
    vector<int> prevsmall(vector<int>& arr) {
        stack<int>st;
        vector<int>ans(arr.size());
        for(int i = 0; i<arr.size(); i++){
            while(!st.empty() && arr[st.top()] > arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? -1 : st.top();
            st.push(i);
        }
        return ans;
    }
    vector<int> nextsmall(vector<int>&arr){
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i = ans.size() -1; i>=0 ;i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty() ? arr.size() : st.top();
            st.push(i);
        }

        return ans;
    }
    int sumSubarrayMins(vector<int>& arr) {
        vector<int> pse = prevsmall(arr);
        vector<int> nse = nextsmall(arr);
        long long total = 0;
        int mod = (int) 1e9 + 7;
        for(int i = 0; i<arr.size(); i++){
            long long left = i - pse[i];
            long long right = nse[i] - i;
            total = (total + (1LL * left * right % mod * arr[i]) % mod) % mod;
        }

        return total%mod;
    }
};