class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        vector<string> row(numRows);
        int r = 0, dir = 1;
        for(char c : s) {
            row[r] += c;
            if(r == 0) dir = 1;
            if(r == numRows - 1) dir = -1;
            r += dir;
        }
        string ans = "";
        for(string x : row)
            ans += x;
        return ans;
    }
};