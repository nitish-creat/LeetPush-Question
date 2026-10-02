class Solution {
public:
    void combine(string &temp,vector<string>&res,int n,int open,int close){
        if(temp.length() == 2*n){
            res.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            combine(temp,res,n,open+1,close);
            temp.pop_back();
        }
        if(close < open){
            temp.push_back(')');
            combine(temp,res,n,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        string temp;
        vector<string> res;
        combine(temp,res,n,0,0);
        return res;
    }
};