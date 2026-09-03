class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;

        // Find smallest odd number
        for (int x : nums1) {
            if (x % 2 == 1) {
                minOdd = min(minOdd, x);
            }
        }

        // Try to make all numbers even
        bool allEven = true;

        for (int x : nums1) {
            if (x % 2 == 1) {
                if (x <= minOdd) {
                    allEven = false;
                    break;
                }
            }
        }

        if (allEven)
            return true;

        // Try to make all numbers odd
        bool allOdd = true;

        for (int x : nums1) {
            if (x % 2 == 0) {
                if (minOdd >= x) {
                    allOdd = false;
                    break;
                }
            }
        }

        return allOdd;
    }
};