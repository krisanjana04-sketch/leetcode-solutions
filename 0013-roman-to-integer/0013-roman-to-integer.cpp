class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;

        for(int i = 0; i < s.size(); i++) {
            int a = 0, b = 0;

            if(s[i] == 'I') a = 1;
            if(s[i] == 'V') a = 5;
            if(s[i] == 'X') a = 10;
            if(s[i] == 'L') a = 50;
            if(s[i] == 'C') a = 100;
            if(s[i] == 'D') a = 500;
            if(s[i] == 'M') a = 1000;

            if(i + 1 < s.size()) {
                if(s[i+1] == 'I') b = 1;
                if(s[i+1] == 'V') b = 5;
                if(s[i+1] == 'X') b = 10;
                if(s[i+1] == 'L') b = 50;
                if(s[i+1] == 'C') b = 100;
                if(s[i+1] == 'D') b = 500;
                if(s[i+1] == 'M') b = 1000;
            }

            if(a < b)
                ans -= a;
            else
                ans += a;
        }

        return ans;
    }
};