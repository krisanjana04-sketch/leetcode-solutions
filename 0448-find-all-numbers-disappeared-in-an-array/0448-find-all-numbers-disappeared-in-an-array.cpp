class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();

        // Mark the index corresponding to each number as negative
        for (int i = 0; i < n; i++) {
            int num = abs(nums[i]);
            int index = num - 1;

            if (nums[index] > 0) {
                nums[index] = -nums[index];
            }
        }

        // Positive positions represent missing numbers
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (nums[i] > 0) {
                ans.push_back(i + 1);
            }
        }

        return ans;
    }
};