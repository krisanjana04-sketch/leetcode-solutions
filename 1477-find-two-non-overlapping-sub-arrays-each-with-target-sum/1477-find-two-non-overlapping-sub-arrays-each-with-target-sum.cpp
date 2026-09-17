class Solution {
public:
    int minSumOfLengths(vector<int>& arr, int target) {
        int n = arr.size();
        vector<int> dp(n, 1000000);

        int left = 0, sum = 0;
        int ans = 1000000;
        int best = 1000000;

        for (int right = 0; right < n; right++) {
            sum += arr[right];

            while (sum > target) {
                sum -= arr[left];
                left++;
            }

            if (sum == target) {
                int len = right - left + 1;

                if (left > 0)
                    ans = min(ans, len + dp[left - 1]);

                best = min(best, len);
            }

            dp[right] = best;
        }

        if (ans == 1000000)
            return -1;

        return ans;
    }
};