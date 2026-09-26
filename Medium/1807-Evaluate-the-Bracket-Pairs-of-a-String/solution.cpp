class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string ,string> mp;
        for(int i = 0;i<knowledge.size(); i++){
            mp[knowledge[i][0]] = knowledge[i][1];
        }
        string res = "";
        int left = 0;
        int right = 0;

        while(right<s.size()){
            if(s[right] == '('){
                left = right;

                while(s[right] != ')') right++;
            
                string temp = s.substr(left+1 , right -left -1);
                if(mp.count(temp)){
                    res += mp[temp];
                }
                else res += '?';
                left = right+1;
            }
            else{
                res += s[right];
            }
            right++;
        }
        return res;
    }
};