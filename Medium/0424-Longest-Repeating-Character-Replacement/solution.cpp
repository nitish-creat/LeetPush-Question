class Solution {
public:
    int characterReplacement(string s, int k) {
        int left = 0 , right = 0, maxi = 0, maxval = 0;
        unordered_map<char,int> mpp;

        while(right < s.size()){
            mpp[s[right]]++;
            maxval = max(maxval, mpp[s[right]]);
            while((right -left +1) - maxval > k){
                mpp[s[left]]--;
                maxval = 0;
                for(auto i : mpp){
                    maxval = max(maxval , i.second);
                }
                left++;
            }
            if(right - left +1 -maxval <= k){
                maxi = max(right -left+1 , maxi);
            }
            right++;
        }

        return maxi;
    }
};