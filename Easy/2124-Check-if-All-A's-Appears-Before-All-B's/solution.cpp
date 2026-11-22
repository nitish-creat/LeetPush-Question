class Solution {
public:
    bool checkString(string s) {
        bool check = false;
        for(auto &i : s){
            if(i == 'a'){
                if(check){
                    return false;
                }
            }
            else if( i == 'b'){
                check = true;
            }
        }

        return true;
    }
};