class Solution {
public:
    int reverse(int x) {
        long long reverse=0;
        int digit;
        while(x!=0){
            digit=x%10;
            reverse= reverse*10 + digit;
            x/=10;
            if(reverse>INT_MAX || reverse<INT_MIN){
                return 0;
            }
        }
        return (int)reverse;
    }
};