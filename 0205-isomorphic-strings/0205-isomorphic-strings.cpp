class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        unordered_map<char, char> st;
        unordered_map<char, char> ts;

        for (int i = 0; i < s.length(); i++) {
            char a = s[i];
            char b = t[i];

            // Check s -> t mapping
            if (st.count(a)) {
                if (st[a] != b)
                    return false;
            } else {
                st[a] = b;
            }

            // Check t -> s mapping
            if (ts.count(b)) {
                if (ts[b] != a)
                    return false;
            } else {
                ts[b] = a;
            }
        }

        return true;
    }
};