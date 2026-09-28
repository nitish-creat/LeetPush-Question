class Solution {
public:
    int maxDepth(string s) {
        int depth = 0;
        int maxi = 0;
        for(auto &i :s){
            if(i == '('){
                depth++;
                maxi = max(maxi,depth);
            }
            else if(i == ')') depth--;
        }

        return maxi;
    }
};