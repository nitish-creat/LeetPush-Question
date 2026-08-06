class Solution {
public:
    int pro(int n){
        string s= to_string(n);
        int p = 1;
        for(auto &i :s){
            p *= i - '0';
        }

        return p;
    }
    int smallestNumber(int n, int t) {
        while(true){
            if(pro(n) % t == 0){
                return n;
            }
            n++;
        }
    }
};