class Solution {
public:
    int numberOfSets(int n, int k) {
        long long ans = 1;
        int mod = 1e9 + 7;
        int a = n + k - 1;
        int b = 2 * k;
        for (int i = 1; i <= b; i++) {
            ans = ans * (a - i + 1) % mod;

            long long inv = 1;
            long long x = i;
            int p = mod - 2;

            while (p) {
                if (p & 1)
                    inv = inv * x % mod;

                x = x * x % mod;
                p >>= 1;
            }

            ans = ans * inv % mod;
        }

        return ans;
    }
};