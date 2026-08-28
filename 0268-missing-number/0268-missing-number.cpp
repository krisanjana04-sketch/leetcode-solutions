class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
int expected = n * (n + 1) / 2;

for (int x : nums) {
    expected -= x;
}

return expected;
    }
};