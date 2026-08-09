class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        // suffix[i] = total stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][m] = maximum stones current player can get
        // starting from index i with M = m
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int i = n - 1; i >= 0; i--) {
            for (int m = n; m >= 1; m--) {

                // If we can take all remaining piles
                if (i + 2 * m >= n) {
                    dp[i][m] = suffix[i];
                    continue;
                }

                int opponentBest = INT_MAX;

                // Try taking X piles
                for (int x = 1; x <= 2 * m && i + x <= n; x++) {
                    int newM = max(m, x);

                    opponentBest = min(
                        opponentBest,
                        dp[i + x][newM]
                    );
                }

                dp[i][m] = suffix[i] - opponentBest;
            }
        }

        return dp[0][1];
    }
};