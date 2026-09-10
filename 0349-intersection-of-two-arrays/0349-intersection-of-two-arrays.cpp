class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        set<int> s;
        vector<int> ans;

        for(int x : nums1) {
            s.insert(x);
        }

        for(int x : nums2) {
            if(s.count(x)) {
                ans.push_back(x);
                s.erase(x);
            }
        }

        return ans;
    }
};