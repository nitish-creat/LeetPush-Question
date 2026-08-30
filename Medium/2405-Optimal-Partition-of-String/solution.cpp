class Solution {
public:
    int partitionString(string s) {
        unordered_set<char> ch;
        int count =1;
        for(auto &i : s){
            if(ch.count(i)){
                count++;
                ch.clear();
            }
            ch.insert(i);
        }
        return count;
    }
};