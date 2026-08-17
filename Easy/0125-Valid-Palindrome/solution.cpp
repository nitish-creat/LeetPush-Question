class Solution {
public:
    bool isPalindrome(string s) {

        string clean= "";
        for(auto c:s){
            if(isalnum(c)){
                clean+=tolower(c);
            }
        }

        // int left=0,right=clean.size()-1;
        // while(left<right){
        //     if(clean[left]!=clean[right])return false;
        //     left++;
        //     right--;
        // }
        // return true;

        string res="";
        for(int i=clean.size()-1;i>=0;i--){
            res+=clean[i];
        }
        if(res==clean) return true;
        else return false;


    }
};