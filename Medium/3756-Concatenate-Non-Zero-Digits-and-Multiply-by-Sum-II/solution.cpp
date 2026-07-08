class Solution {
public:
    int M = 1e9 + 7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& q) {
        int n =s.size();
        vector<int> nonZeroCount(n , 0);
        vector<ll> number(n ,0);
        vector<ll> digitsum(n ,0);
        vector<ll> power(n+1 ,0);
        power[0] = 1;

        for(int i = 1;i<n; i++){
            power[i] = (power[i -1]*10) % M;
        }
        nonZeroCount[0] = (s[0] != '0') ? 1 : 0;
        for(int i = 1;i<n ;i++){
            nonZeroCount[i] = nonZeroCount[i -1] + ((s[i] !='0') ? 1 : 0);
        }

        number[0] = s[0] - '0';
        for(int i = 1 ;i<n;i++){
            int digit = s[i] - '0';
            if(digit !=0){
                number[i] = ((number[i-1] * 10) + digit) % M;
            }
            else{
                number[i] = number[i-1];
            }
        }

        digitsum[0] = s[0] - '0';
        for(int i = 1 ;i<n; i++){
            digitsum[i] = digitsum[i-1] + (s[i] - '0');
        }
        vector<int> ans(q.size());
        for(int i = 0;i<q.size() ;i++){
            int left = q[i][0];
            int right = q[i][1];

            ll sum = digitsum[right] - ((left == 0) ? 0 : digitsum[left-1]); 
            int num = (left == 0)? 0 : number[left-1];
            int k = nonZeroCount[right] - ((left == 0) ? 0 : nonZeroCount[left-1]);

            ll x = (number[right] - (num * power[k] % M) + M) % M;

            ans[i] = (int)((x * sum)%M);
        }

        return ans;
    }
};