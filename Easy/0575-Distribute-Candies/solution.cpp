class Solution {
public:
    int distributeCandies(vector<int>& candy) {
        unordered_set<int> st;
        for(auto &i : candy){
            st.insert(i);
        }

        int n = candy.size()/2;
        int count = 0;
        for(auto &i : st){
            if(count >= n) break;
            count++;
        }

        return count;
    }
};