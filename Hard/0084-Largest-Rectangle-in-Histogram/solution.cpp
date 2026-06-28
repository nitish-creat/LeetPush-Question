class Solution {
public:
    vector<int> prevsmall(vector<int>&arr){
        stack<int> st;
        vector<int> ans(arr.size());
        for(int i =0;i<arr.size();i++){
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
        for(int i =arr.size()-1 ;i>=0; i--){
            while(!st.empty() && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.empty()? arr.size() : st.top();
            st.push(i);
        }
        return ans;
    }
    int largestRectangleArea(vector<int>& arr) {
        int maxTotal = 0;
        vector<int> pse = prevsmall(arr);
        vector<int> nse = nextsmall(arr);
        for(int i = 0; i<arr.size();i++){
            int left = pse[i];
            int right = nse[i];
            int total = arr[i] * (right - left -1);
            maxTotal = max(maxTotal , total);
        }

        return maxTotal;
    }
};