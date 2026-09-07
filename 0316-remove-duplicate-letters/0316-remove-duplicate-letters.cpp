class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> last(26, 0);
        vector<bool> used(26, false);

        // Store last occurrence of every character
        for (int i = 0; i < s.size(); i++) {
            last[s[i] - 'a'] = i;
        }

        string st;

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];

            // Already present in answer
            if (used[c - 'a']) {
                continue;
            }

            // Remove larger characters if they occur again later
            while (!st.empty() &&
                   st.back() > c &&
                   last[st.back() - 'a'] > i) {

                used[st.back() - 'a'] = false;
                st.pop_back();
            }

            st.push_back(c);
            used[c - 'a'] = true;
        }

        return st;
    }
};