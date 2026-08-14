class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char , int> mp;
        int left = 0 , right = 0;
        int n = s.size();
        int ans = 0;
        while(right < n){
            mp[s[right]]++;
            while(mp[s[right]] > 2){
                mp[s[left]]--;
                left++;
            }
            ans = max(ans , right - left+1);
            right++;
        }
        return ans;
    }
};