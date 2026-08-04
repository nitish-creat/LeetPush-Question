class Solution {
public:
    bool isLongPressedName(string name, string typed) {
        if(name.size() > typed.size()) return false;
        int left = 0;
        int right = 0;
        while(left < name.size() && right < typed.size()){
            if(name[left] == typed[right]){
                left++;
                right++;
            }
            else{
                if(left == 0 || name[left -1] != typed[right]){
                    return false;
                }
                right++;
            }
        }
        if(left != name.size()) return false;
        
        while(right < typed.size()){
            if(typed[right] != typed[right -1]){
                return false;
            }
            right++;
        }
        return true;
    }
};