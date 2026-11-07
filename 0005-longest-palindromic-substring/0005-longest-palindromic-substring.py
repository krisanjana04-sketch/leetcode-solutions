class Solution(object):
    def longestPalindrome(self, s):
        ans = ""
        for i in range(len(s)):
            for j in range(i, len(s)):
                sub = s[i:j+1]
                if sub == sub[::-1] and len(sub) > len(ans):
                    ans = sub
        return ans