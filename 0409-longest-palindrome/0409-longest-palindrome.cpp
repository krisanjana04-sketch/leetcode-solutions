class Solution {
public:
int longestPalindrome(string s) {
int a[128] = {};
int ans = 0;


    for (char c : s)
        a[c]++;

    for (int i = 0; i < 128; i++)
        ans += (a[i] / 2) * 2;

    for (int i = 0; i < 128; i++) {
        if (a[i] % 2) {
            ans++;
            break;
        }
    }

    return ans;
}


};

