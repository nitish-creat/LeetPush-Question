class Solution {
public:
    int minimumRecolors(string s, int k) {
        int left = 0;
        int right = 0;
        int ans = INT_MAX;
        int count = 0;
        while(right < s.size()){
            if(s[right] == 'W') count++;
            
            if(right - left +1 > k){
                if(s[left] == 'W') count--;
                left++;
            }
            if(right - left +1 == k){
                ans = min(ans , count);
            }
            right++;
        }

        return ans;
    }
};