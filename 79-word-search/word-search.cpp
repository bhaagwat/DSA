class Solution {
public:
    bool findWord(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (index == word.size()) {
            return true;
        }

        if (row < 0 || col < 0 || row >= board.size() || col >= board[0].size()
            || board[row][col] != word[index]) {
            return false;
        }

        char temp = board[row][col];
        board[row][col] = '#';  // mark as visited

        bool found =
            findWord(board, word, row + 1, col, index + 1) ||
            findWord(board, word, row - 1, col, index + 1) ||
            findWord(board, word, row, col + 1, index + 1) ||
            findWord(board, word, row, col - 1, index + 1);

        board[row][col] = temp; // put original character back
        return found;
    }

    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (findWord(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
};