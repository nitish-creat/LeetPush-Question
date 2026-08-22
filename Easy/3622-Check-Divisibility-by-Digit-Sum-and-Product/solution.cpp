class Solution {
public:
    bool checkDivisibility(int n) {
        string s = to_string(n);
        int sum = 0;
        int pro =1;
        for(auto &i:s){
            sum += i - '0';
            pro *= i - '0';
        }

        if(n % (pro + sum) == 0) return true;
        return false;
    }
};