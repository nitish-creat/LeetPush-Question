class Solution {
public:
    void combine(int ind ,string s,map<char,string>&mpp, vector<string>&temp,string&dum){
        if(ind == s.size()){
            temp.push_back(dum);
            return;
        }
        char ch = s[ind];
        string str = mpp[ch];
        for(int i=0;i<str.size();i++){
            dum.push_back(str[i]);
            combine(ind+1,s,mpp,temp,dum);
            dum.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> temp;
        map<char,string> mp = {
            {'2' , "abc"},
            {'3' , "def"},
            {'4' , "ghi"},
            {'5' , "jkl"},
            {'6' , "mno"},
            {'7' , "pqrs"},
            {'8' , "tuv"},
            {'9' , "wxyz"}
        };
        string dum = "";
        combine(0,digits, mp , temp,dum);

        return temp;
        
    }
};