class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int> st;

        // Put all elements into the set
        for (int x : nums) {
            st.insert(x);
        }

        // Check positive multiples of k
        int multiple = k;

        while (st.count(multiple)) {
            multiple += k;
        }

        return multiple;
    }
};