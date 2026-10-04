class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int a = 0, b = 0;
        for (int i = 1; i <= n; i++) {
            int count = 0;
            for (int x : nums) {
                if (x == i) count++;
            }
            if (count == 2) a = i;
            if (count == 0) b = i;
        }
        return {a, b};
    }
};