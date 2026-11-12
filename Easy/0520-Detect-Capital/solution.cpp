class Solution {
public:
    bool detectCapitalUse(string word) {
        bool cap = true;
        bool small = true;
        bool first = true;

        for(auto &i : word){
            if(isupper(i)) small = false;
            if(islower(i)) cap = false;
        }
        for(int i = 0;i<word.size(); i++){
            if(i == 0 && isupper(word[i])) continue;
            if(isupper(word[i])) first = false;
        }

        return cap || small || first;
    }
};