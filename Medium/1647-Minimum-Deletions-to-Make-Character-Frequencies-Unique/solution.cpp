class Solution {
public:
    int minDeletions(string s) {
        unordered_map<char,int> mp;
        for(auto &i : s) mp[i]++;
         
        unordered_set<int> st;
        int count = 0;
        for(auto &i : mp){
            int freq = i.second;
            while(st.count(freq)){
                freq--;
                count++;
            }
            if(freq > 0) st.insert(freq);
        }

        return count;
        
    }
};