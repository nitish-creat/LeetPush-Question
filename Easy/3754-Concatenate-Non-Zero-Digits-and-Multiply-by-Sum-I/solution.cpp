class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum = 0;
        string s ="";
        while(n > 0){
            int digit = n%10;
            sum += digit;
            if(digit != 0){
                s += to_string(digit);
            }
            n /= 10;
        }

        if(s.empty()) return 0;
        reverse(s.begin(),s.end());
        long long x = stoll(s);

        return x * sum;
        
    }
};