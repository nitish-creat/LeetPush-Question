class Solution {
public:
    string Rotate(string s , int step){
        string temp= s.substr(0,step);
        return s.substr(step) + temp;
    }
    bool rotateString(string s, string goal) {
        for(int i=0;i<s.size();i++){
            if(Rotate(s,i) == goal){
                return true;
            }
        }
        return false;
    }
};