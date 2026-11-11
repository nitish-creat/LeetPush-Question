class Solution {
public:
    bool isPalindrome(string &s , int start , int end){
        while(start <= end){
            if(s[start] != s[end]){
                return false;
            }
            start++;
            end--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        string ans="";
        int maxLen = 0;
        for(int i=0;i<s.size();i++){
            for(int j=i;j<s.size();j++){   
                if(isPalindrome(s,i,j)){
                    if(maxLen < j-i+1){
                        maxLen = j-i +1;
                        ans = s.substr(i,j-i+1);
                    }
                }
            }
        }
        return ans;
    }
};