class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans = "";
        if(num * 9 < sum) return ans;
        while(num > 0){
            int digit = min(9,sum);
            ans += digit + '0';
            sum -= digit;
            num--;
        }

        return ans;
    }
};