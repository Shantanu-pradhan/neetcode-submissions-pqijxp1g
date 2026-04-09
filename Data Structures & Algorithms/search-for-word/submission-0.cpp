class Solution {
public:
    int R, C;
    bool exist(vector<vector<char>>& board, string word) {
        R = board.size();
        C = board[0].size();
        for(int i=0; i<R; i++){
            for(int j=0; j<C; j++)
            {
                if(find_word(i, j, board, word, 0))
                {
                    return true;
                }
            }
        }
        return false;
    }
    bool find_word(int row, int col, vector<vector<char>>&board, string word, int indx)
    {
        bool res = false;
        if(indx == word.size())
        {
            return true;
        }
        if( row < 0 || col < 0 ||
            row >= R || col >= C ||
            word[indx] != board[row][col] ||
            board[row][col] == '#'){
            return false;
        }
        board[row][col] = '#';
        res =   find_word(row, col+1, board, word, indx+1) ||
                find_word(row, col-1, board, word, indx+1) ||
                find_word(row+1, col, board, word, indx+1) ||
                find_word(row-1, col, board, word, indx+1);
        board[row][col] = word[indx];
        return res;
    }
};
