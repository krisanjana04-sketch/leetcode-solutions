class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        vector<string> ans;
        string a="qwertyuiop", b="asdfghjkl", c="zxcvbnm";

        for(string s:words){
            string t=s;
            for(char &x:t) x=tolower(x);

            int row = (a.find(t[0])!=string::npos) ? 1 :
                      (b.find(t[0])!=string::npos) ? 2 : 3;

            bool ok=true;
            for(char x:t){
                if((row==1 && a.find(x)==string::npos) ||
                   (row==2 && b.find(x)==string::npos) ||
                   (row==3 && c.find(x)==string::npos))
                    ok=false;
            }

            if(ok) ans.push_back(s);
        }
        return ans;
    }
};