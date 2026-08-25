class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char,int> mp;
        int left =0;
        int right =0;
        for(int i = 0;i<s.size(); i++){
            mp[s[i]] = i;
        }
        vector<int> ans;
        while(right < s.size()){
            int last = mp[s[right]];
            int end = max(last , end);
            if(right == end){
                ans.push_back(right - left +1);
                left = end + 1;
            }  
            right++;
        }

        return ans;
    }
};