class Solution {
public:
    string toHex(int num) {
     if (num == 0) return "0";
     unsigned int n = num;
        string s = "0123456789abcdef";
        string ans = "";
        while (n) {
            ans += s[n % 16];
            n /= 16;
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};