class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res = "";
        int left = 0;
        int right = 0;
        while(right < s.size()){
            if(spaces.size() > left && spaces[left] == right){
                res += ' ';
                left++;
            }
            res += s[right];
            right++;
        }

        return res;
    }
};