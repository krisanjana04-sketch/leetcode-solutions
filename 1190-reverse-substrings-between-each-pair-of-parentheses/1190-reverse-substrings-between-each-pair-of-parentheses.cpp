class Solution {
public:
    string reverseParentheses(string s) {
        string ans = "";
        vector<string> st;

        for(char c : s) {
            if(c == '(') {
                st.push_back(ans);
                ans = "";
            }
            else if(c == ')') {
                reverse(ans.begin(), ans.end());
                ans = st.back() + ans;
                st.pop_back();
            }
            else {
                ans += c;
            }
        }

        return ans;
    }
};