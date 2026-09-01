class Solution {
public:
    int minAddToMakeValid(string s) {
        int size = 0;
        int count = 0;
        for(auto &i : s){
            if(i == '(') size++;
            else if(i == ')' && size > 0){
                size--;
            }
            else count++;
        }
        return count + size;
    }
};