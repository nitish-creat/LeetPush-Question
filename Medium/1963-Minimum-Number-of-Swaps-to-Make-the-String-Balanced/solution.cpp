class Solution {
public:
    int minSwaps(string s) {
        stack<int> st;
        for(auto &i : s){
            if( i == '['){
                st.push(i);
            }
            else{
                if(st.size() > 0) st.pop();
            }
        }

        return (st.size() +1)/2;
    }
};