class Solution {
public:
    int R;
    int C;
    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++){
                if(find_word(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    bool find_word(vector<vector<char>>&board, string word, int r, int c, int i)
    {
        bool res;
        if(i == word.size()){
            return true;
        }
        if(r < 0 || c < 0 || r >= R || c >= C || board[r][c] == '#' ||
            board[r][c] != word[i]){
            return false;
        }
        board[r][c] = '#';
        res =   find_word(board, word, r+1, c, i+1) ||
                find_word(board, word, r-1, c, i+1) ||
                find_word(board, word, r, c+1, i+1) ||
                find_word(board, word, r,c-1, i+1);
        board[r][c] = word[i];
        return res;
    }
};
