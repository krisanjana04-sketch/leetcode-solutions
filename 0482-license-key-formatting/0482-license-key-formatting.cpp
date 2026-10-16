class Solution {
public:
    string licenseKeyFormatting(string s, int k) {
        string ans = "";
        for (char c : s) {
            if (c != '-') {
                ans += toupper(c);
            }
        }
        string res = "";
        int count = 0;
        for (int i = ans.size() - 1; i >= 0; i--) {
            res += ans[i];
            count++;
            if (count == k && i != 0) {
                res += '-';
                count = 0;
            }
        }
        reverse(res.begin(), res.end());
        return res;
    }
};