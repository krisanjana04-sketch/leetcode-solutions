class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            int x = num % k;

            vector<long long> next(k, 0);

            // Start a new subarray
            next[x]++;

            // Extend previous subarrays
            for (int r = 0; r < k; r++) {
                int newR = (r * x) % k;
                next[newR] += dp[r];
            }

            // Add to final answer
            for (int r = 0; r < k; r++) {
                ans[r] += next[r];
            }

            dp = next;
        }

        return ans;
    }
};