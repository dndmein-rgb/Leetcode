class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int i = 0; i < 9; i++) {
            unordered_set<char> rowSet;
            unordered_set<char> colSet;

            for(int j = 0; j < 9; j++) {

                if(board[i][j] != '.') {
                    if(rowSet.count(board[i][j])) return false;
                    rowSet.insert(board[i][j]);
                }

                if(board[j][i] != '.') {
                    if(colSet.count(board[j][i])) return false;
                    colSet.insert(board[j][i]);
                }
            }
        }

        for(int boxRow = 0; boxRow < 9; boxRow += 3) {
            for(int boxCol = 0; boxCol < 9; boxCol += 3) {

                unordered_set<char> boxSet;

                for(int i = boxRow; i < boxRow + 3; i++) {
                    for(int j = boxCol; j < boxCol + 3; j++) {

                        if(board[i][j] == '.') continue;

                        if(boxSet.count(board[i][j])) return false;
                        boxSet.insert(board[i][j]);
                    }
                }
            }
        }

        return true;
    }
};