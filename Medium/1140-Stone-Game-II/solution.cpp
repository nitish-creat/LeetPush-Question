class Solution {
public:
    int n;
    vector<int> suf;
    vector<vector<int>> dp;

    int solve(int i, int M) {
        if (i >= n) return 0;
        if (dp[i][M] != -1) return dp[i][M];

        int ans = 0;

        for (int x = 1; x <= 2 * M && i + x <= n; x++) {
            ans = max(ans,
                suf[i] - solve(i + x, max(M, x)));
        }

        return dp[i][M] = ans;
    }

    int stoneGameII(vector<int>& piles) {
        n = piles.size();
        suf.resize(n + 1);

        for (int i = n - 1; i >= 0; i--)
            suf[i] = suf[i + 1] + piles[i];

        dp.assign(n, vector<int>(n + 1, -1));

        return solve(0, 1);
    }
};