class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& arr) {
        long long ans = 0;
        long long even = 1 , odd = 0;
        int prefix= 0;

        for(auto &i : arr){
            prefix += i;

            if(prefix %2 == 0){
                ans += odd;
                even++;
            }
            else{
                ans += even;
                odd++;
            }

            ans %= mod;
        }

        return ans;
    }
};