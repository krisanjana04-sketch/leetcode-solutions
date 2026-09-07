class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string word;

        // Split s into words
        stringstream ss(s);
        while (ss >> word) {
            words.push_back(word);
        }

        // Number of pattern characters and words must match
        if (pattern.size() != words.size()) {
            return false;
        }

        unordered_map<char, string> charToWord;
        unordered_map<string, char> wordToChar;

        for (int i = 0; i < pattern.size(); i++) {
            char c = pattern[i];
            string w = words[i];

            // Character already mapped
            if (charToWord.count(c)) {
                if (charToWord[c] != w) {
                    return false;
                }
            }

            // Word already mapped to another character
            if (wordToChar.count(w)) {
                if (wordToChar[w] != c) {
                    return false;
                }
            }

            // Establish mapping
            charToWord[c] = w;
            wordToChar[w] = c;
        }

        return true;
    }
};