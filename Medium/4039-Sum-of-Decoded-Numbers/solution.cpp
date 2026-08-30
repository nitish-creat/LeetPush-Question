class Solution {
public:
    int mod = 1e9 + 7;
    long long power(long long x , long long y){
        long long ans = 1;
        while( y > 0){
            if(y % 2==1){
                ans = (ans * x) % mod;
            }
            x = (x*x) % mod;
            y /= 2;
        }

        return ans;
    }
    int sumDecoded(vector<long long>& nums) {
        long long sum = 0;
        for(int i = 0;i<nums.size(); i++){
            int width = nums[i] % 10;
            long long d = floor(nums[i] / 10);
            string s = to_string(d);
            int x = stoi(s.substr(0,width));
            int y = stoi(s.substr(width , s.size()));

            sum = (sum + power(x,y)) % mod;
        }

        return sum;
    }
};