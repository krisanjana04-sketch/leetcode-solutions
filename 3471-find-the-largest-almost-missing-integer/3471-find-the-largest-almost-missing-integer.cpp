class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        int count[51] = {0};

        // Count frequency
        for (int x : nums) {
            count[x]++;
        }

        // k = 1
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if (count[i] == 1)
                    return i;
            }
            return -1;
        }

        // k = n
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        // 1 < k < n
        int ans = -1;

        if (count[nums[0]] == 1)
            ans = max(ans, nums[0]);

        if (count[nums[n - 1]] == 1)
            ans = max(ans, nums[n - 1]);

        return ans;
    }
};