class Solution {
public:
    bool search(vector<vector<char>>& b, string w, int i, int j, int k) {
        if (k == w.size()) return true;
        if (i < 0 || j < 0 || i >= b.size() || j >= b[0].size() || b[i][j] != w[k])
            return false;

        char ch = b[i][j];
        b[i][j] = '#';

        bool x = search(b,w,i+1,j,k+1) ||
                 search(b,w,i-1,j,k+1) ||
                 search(b,w,i,j+1,k+1) ||
                 search(b,w,i,j-1,k+1);

        b[i][j] = ch;
        return x;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
            for(int j=0;j<board[0].size();j++)
                if(search(board,word,i,j,0)) return true;

        return false;
    }
};