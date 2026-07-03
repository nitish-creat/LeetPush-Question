class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        if(t.size() > n) return "";
        unordered_map<int,int> mp;
        for(auto &i : t){
            mp[i]++;
        }
        int left = 0,right = 0;
        int window = INT_MAX;
        int start_i = 0;
        int remain = t.size();

        while(right < n){
            char ch = s[right];
            if(mp[ch] > 0){
                remain--;
            }
            mp[ch]--;

            while(remain == 0){
                int curr = right - left+1;
                if(window > curr){
                    window = curr;
                    start_i = left;
                }
                mp[s[left]]++;
                if(mp[s[left]] > 0){
                    remain++;
                }
                left++;
            }

            right++;
        }


        return (window == INT_MAX)? "": s.substr(start_i , window);
    }
};