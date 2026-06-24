class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> s1;
        int left = 0;
        int ans = 0;
        for(int i = 0 ; i<s.size() ; i++){
            while(s1.find(s[i]) != s1.end()){
                s1.erase(s[left]);
                left++;
            }
            s1.insert(s[i]);
            ans = max(ans , i - left + 1);
        }
        return ans;
        
    }
};